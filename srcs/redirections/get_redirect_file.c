/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:05:39 by ebini             #+#    #+#             */
/*   Updated: 2025/08/20 05:05:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>

#include "utils.h"
#include "identifier.h"
#include "libft.h"
#include "parsing/expand.h"

#include <stdio.h>

/**
 * for convenience, this function should return a pointer to the parsed file
 * name allocated and set the parsed string len to the pointeur `arg_len`
 * for instance :
 *   - f"i"l'e' will set *arg_len to 8 and return a pointer to "file\0"
 */
char	*get_redirect_file(char *arg, size_t *arg_len)
{
	size_t	filename_len;
	char	*raw_filename;
	char	*filename;

	*arg_len = (*arg == '<' || *arg == '>') + (*(arg + 1) == '>');
	while (is_space(arg[*arg_len]))
		++*arg_len;
	arg += *arg_len;
	filename_len = 0;
	while (arg[filename_len] && !is_space(arg[filename_len]))
	{
		if (arg[filename_len] == '\'')
			skip_squote(arg, &filename_len);
		else if (arg[filename_len] == '"')
			skip_dquote(arg, &filename_len);
		else
			++filename_len;
	}
	*arg_len += filename_len;
	raw_filename = ft_strndup(arg, filename_len);
	if (!raw_filename)
		return (NULL);
	filename = parse_arg(raw_filename, true);
	free(raw_filename);
	return (filename);
}
