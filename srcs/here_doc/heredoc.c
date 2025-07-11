/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:04 by ebini             #+#    #+#             */
/*   Updated: 2025/07/11 05:13:03 by ebini            ###   ########lyon.fr   */
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

int	clear_here_doc(int fd, char *file, char *line)
{
	close(fd);
	free(line);
	unlink(file);
	free(file);
	return (-1);
}

int	create_here_doc(char *limiter)
{
	char		*file;
	char		*line;
	const int	fd = tmp_fd(&file, O_WRONLY);

	if (fd == -1)
		return (-1);
	errno = 0;
	line = readline("heredoc>");
	while (line && ft_strcmp(line, limiter))
	{
		if (write_line(fd, line, true) == -1)
			return (clear_here_doc(fd, file, line));
		free(line);
		line = readline("heredoc>");
	}
	if (!line)
	{
		if (errno)
		{
			perror("gigachell: readline");
			return (clear_here_doc(fd, file, NULL));
		}
		write(2, "warning: expected limiter before EOF\n", 37);
	}
	return (exit_here_doc(fd, line, file));
}
