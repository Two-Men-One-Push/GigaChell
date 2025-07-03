/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:02:29 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/01 20:24:20 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stdio.h>

int	syntax_in(t_syntax_attr *attr)
{
	if (attr->token == -1)
	{
		printf("minishell: syntax error near <\n");
		return (1);
	}
	attr->last_operator = 4;
	attr->token = -1;
	return (0);
}
