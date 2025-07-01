/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:49:30 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/01 20:23:24 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stddef.h>
#include <stdio.h>

int	syntax_pipe(t_syntax_attr *attr)
{
	if (attr->token == 0)
	{
		printf("minishell: syntax error near |\n");
		return (1);
	}
	attr->last_operator = 3;
	attr->token = 0;
	return (0);
}
