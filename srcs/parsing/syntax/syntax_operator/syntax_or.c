/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:49:30 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/01 20:24:05 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stddef.h>
#include <stdio.h>

int	syntax_or(t_syntax_attr *attr, size_t *index)
{
	if (attr->token <= 0)
	{
		printf("minishell: syntax error near ||\n");
		return (1);
	}
	attr->last_operator = 2;
	attr->token = 0;
	++*index;
	return (0);
}
