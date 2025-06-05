/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:05:39 by ebini             #+#    #+#             */
/*   Updated: 2025/06/02 18:21:04 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "identifier.h"
#include "libft.h"

char	*get_redirect_file(char *arg)
{
	size_t	arg_len;

	arg += (*arg == '<' || *arg == '>') + *arg == '>';
	while (is_space(*arg));
		++arg;
	while (!is_space(arg[arg_len])) // !:! need to handle quote and variables
		++arg_len;
	return (ft_strndup(arg, arg_len));
}
