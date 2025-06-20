/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_squote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:57:27 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/12 09:09:41 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstring.h"
#include <stddef.h>
#include "syntax.h"
#include <unistd.h>

int	syntax_squote(t_syntax_attr *attr, t_string string, size_t *index)
{
	if (skipto(string.ptr, index, '\''))
		return (write(2, "minishell: syntax error unclosed \'\n", 36));
	attr->token = 1;
	return (0);
}
