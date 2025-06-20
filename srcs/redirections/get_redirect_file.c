/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:05:39 by ebini             #+#    #+#             */
/*   Updated: 2025/06/15 09:03:41 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "identifier.h"
#include "libft.h"
/**
 * for convenience, this function should return the full size of the word read
 * and set the parsed filename in the pointeur `file_result`
 * for instance :
 *   - f"i"l'e' will return 8
 */
char	*get_redirect_file(char *arg)
{
	//WIP
	size_t	arg_len;

	arg += (*arg == '<' || *arg == '>') + *arg == '>';
	while (is_space(*arg))
		++arg;
	arg_len = 0;
	while (!is_space(arg[arg_len])) // !:! need to handle quote and variables
		++arg_len;
	return (ft_strndup(arg, arg_len));
}
