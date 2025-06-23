/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:05:39 by ebini             #+#    #+#             */
/*   Updated: 2025/06/17 11:11:52 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

#include "identifier.h"
#include "libft.h"

#include <stdio.h>

/**
 * for convenience, this function should return a pointer to the parsed file
 * name allocated and set the parsed string to the pointeur `arg_len`
 * for instance :
 *   - f"i"l'e' will set *arg_len to 8 and return a pointer to "file\0"
 */
char	*get_redirect_file(char *arg, size_t *arg_len)
{
	size_t	file_name_len;

	*arg_len = (*arg == '<' || *arg == '>') + (*(arg + 1) == '>');
	arg += *arg_len;
	while (is_space(arg[*arg_len]))
		++*arg_len;
	arg += *arg_len;
	file_name_len = 0;
	while (arg[file_name_len] && !is_space(arg[file_name_len])) // !:! need to handle quote and variables
		++file_name_len;
	*arg_len += file_name_len;
	return (ft_strndup(arg, file_name_len));
}
