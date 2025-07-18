/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_squote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:57:27 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/01 20:22:57 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstring.h"
#include <stddef.h>
#include "syntax.h"
#include <stdio.h>

int	syntax_squote(t_syntax_attr *attr, char *str, size_t *index)
{
	if (skipto(str, index, '\''))
	{
		printf("minishell: syntax error unclosed '\n");
		return (1);
	}
	attr->token = 1;
	return (0);
}
