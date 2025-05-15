/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:38:45 by ebini             #+#    #+#             */
/*   Updated: 2025/05/15 20:13:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "libft.h"

bool are_same_path(const char *path1, const char *path2)
{
	struct stat st1;
	struct stat st2;

	if (stat(path1, &st1) != 0 || stat(path2, &st2) != 0)
		return (0);
	return ((st1.st_ino == st2.st_ino) && (st1.st_dev == st2.st_dev));
}

void remove_path_dot(char *path, size_t i)
{
	const size_t next_len = ft_strlen(path + i + 2);

	ft_memmove(path + i + 2, path + i, next_len + 1);
}

void remove_path_dot_dot(char *path, size_t *i)
{
	const size_t next_len = ft_strlen(path + 3);
	size_t next_pos;

	if (*i == 1)
		ft_memmove(path + *i + 3, path + *i, next_len + 1);
	else
	{
		next_pos = *i + 3;
		*i -= 2;
		while (path[*i] != '/')
			--*i;
		++*i;
		ft_memmove(path + next_pos, path + *i, next_len + 1);
	}
}

void clean_path_slash(char *path, size_t i)
{
	size_t slash_count;

	slash_count = 0;
	while (path[++slash_count + i] == '/')
		;
	ft_memmove(path + slash_count + i, path + i,
			   ft_strlen(path + i + slash_count));
}

void	handle_path_end(char *path, size_t len)
{
	if (path[len - 1] == '/' && len > 1)
		path[len - 1] = '\0';
	else if (path[len - 2] == '/' && path[len - 1] == '.')
		path[len - 2] = '\0';
	else if (path[len - 3] == '/' && path[len - 2] == '.' && path[len - 1] == '.')
	{
		if (len == 3)
			path[1] = '\0';
		else
		{
			len -= 4;
			while (path[len] != '/')
				--len;
			++len;
			path[len] = '\0';
		}
	}
}
