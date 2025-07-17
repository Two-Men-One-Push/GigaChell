/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 06:34:01 by ebini             #+#    #+#             */
/*   Updated: 2025/01/29 07:43:27 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "libft.h"
#include "heredoc.h"
#include "utils.h"

static char	*make_readable_string(char *str)
{
	size_t			i;
	unsigned char	*pos_str;

	pos_str = (unsigned char *)str;
	i = -1;
	while (pos_str[++i])
		pos_str[i] = pos_str[i] % 26 + 'a';
	return (str);
}

static char	*generate_random_string(size_t n)
{
	const int	fd = open(RANDOM_FILE, O_RDONLY);
	char		*string;

	if (fd == -1)
	{
		perror("gigachell: Can't open /dev/urandom");
		return (NULL);
	}
	string = malloc((n + 1) * sizeof(char));
	if (!string)
	{
		perror("gigachell");
		close(fd);
		return (NULL);
	}
	if (read(fd, string, n) != (ssize_t)n)
	{
		perror("gigachell: Can't read /dev/urandom");
		free(string);
		close(fd);
		return (NULL);
	}
	string[n] = '\0';
	close(fd);
	return (make_readable_string(string));
}

char	*tmp_path(void)
{
	char	*path;
	char	*random_string;
	int		try_no;

	try_no = 0;
	while (try_no < RANDOM_FILE_TRY_MAX)
	{
		random_string = generate_random_string(20);
		if (!random_string)
			return (NULL);
		path = ft_strjoin(GIGACHELL_TMP_PATH, random_string);
		free(random_string);
		if (!path)
		{
			perror("gigachell: tmp_path");
			return (NULL);
		}
		if (access(path, F_OK) == -1 && errno == ENOENT)
			return (path);
		free(path);
		++try_no;
	}
	write(STDERR_FILENO,
		"gigachell: Couldn't generate temporary file for heredoc\n", 56);
	return (NULL);
}

int	tmp_fd(char **path, int flags)
{
	int		fd;

	*path = tmp_path();
	if (!*path)
		return (-1);
	fd = open(*path, flags | O_CREAT, 0600);
	if (fd == -1)
	{
		free(*path);
		perror("gigachell");
		return (-1);
	}
	return (fd);
}
