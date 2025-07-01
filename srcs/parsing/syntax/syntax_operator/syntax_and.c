/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:43:13 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/01 20:25:41 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stddef.h>
#include <stdio.h>
#include <stdio.h>

int	syntax_and(t_syntax_attr *attr, size_t *index)
{
	if (attr->token <= 0)
	{
		printf("minishell: syntax error near &&\n");
		return (1);
	}
	attr->last_operator = 1;
	attr->token = 0;
	++*index;
	return (0);
}
