/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:04 by ebini             #+#    #+#             */
/*   Updated: 2025/08/19 16:29:13 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h> 
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

#include "libft.h"
#include "utils.h"
#include "parsing/expand.h"
#include "signal_handling.h"
#include "global.h"
#include "defs/configs.h"

int	write_line(int fd, char *line, bool parse)
{
	size_t	line_len;

	if (parse)
		line = parse_arg(line, false);
	line_len = ft_strlen(line);
	line[line_len] = '\n';
	++line_len;
	if (write(fd, line, line_len) != (ssize_t)line_len)
	{
		perror("gigachell: write");
		if (parse)
			free(line);
		return (-1);
	}
	if (parse)
		free(line);
	return (0);
}

int	exit_here_doc(int fd, char *line, char *file)
{
	int	result_fd;

	free(line);
	close(fd);
	result_fd = open(file, O_RDONLY);
	unlink(file);
	free(file);
	if (result_fd == -1)
		perror("gigachell");
	return (result_fd);
}

int	handle_loop_end(char *line)
{
	if (!line)
	{
		if (errno)
		{
			perror("gigachell");
			return (-1);
		}
		write(2, "warning: expected limiter before EOF\n", 37);
	}
	free(line);
	return (0);
}

static int	heredoc_loop(int fd, char *limiter, bool expand)
{
	char		*line;

	errno = 0;
	line = readline(HEREDOC_PROMPT);
	while (line && ft_strcmp(line, limiter))
	{
		if (g_sigint)
		{
			g_sigint = 0;
			free(line);
			return (-2);
		}
		if (write_line(fd, line, expand) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = readline(HEREDOC_PROMPT);
	}
	return (handle_loop_end(line));
}

int	create_here_doc(char *limiter, bool expand)
{
	char	*filename;
	int		fd;
	int		heredoc_loop_result;

	fd = tmp_fd(&filename, O_WRONLY);
	if (fd == -1)
		return (-1);
	handling_heredoc_signal();
	heredoc_loop_result = heredoc_loop(fd, limiter, expand);
	handling_execution_signal();
	close(fd);
	if (heredoc_loop_result)
	{
		unlink(filename);
		free(filename);
		return (heredoc_loop_result);
	}
	fd = open(filename, O_RDONLY);
	unlink(filename);
	free(filename);
	if (fd < 0)
		perror("minishell");
	return (fd);
}
