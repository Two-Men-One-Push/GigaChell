/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:04 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 22:41:21 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h> 
#include <errno.h>
#include <stdlib.h>
#include <readline/readline.h>

#include "libft.h"
#include "utils.h"

int	write_line(int fd, char *line)
{
	const size_t	line_len = ft_strlen(line);

	if (write(fd, line, line_len) != (ssize_t)line_len)
	{
		perror("gigachell");
		return (-1);
	}
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
	ft_dprintf(2, "%s\n", limiter);
	line = readline("heredoc>");
	while (line && ft_strcmp(line, limiter))
	{
		if (write_line(fd, line) == -1)
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
