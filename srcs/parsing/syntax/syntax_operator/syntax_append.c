/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:02:00 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/01 20:25:28 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stddef.h>
#include <stdio.h>

int	syntax_append(t_syntax_attr *attr, size_t *index)
{
	if (attr->token == -1)
	{
		printf("minishell: syntax error near >>\n");
		return (1);
	}
	attr->last_operator = 7;
	attr->token = -1;
	++*index;
	return (0);
}
