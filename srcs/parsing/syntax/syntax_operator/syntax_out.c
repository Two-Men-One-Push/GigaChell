/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:02:33 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/01 20:23:46 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stdio.h>

int	syntax_out(t_syntax_attr *attr)
{
	if (attr->token == -1)
	{
		printf("minishell: syntax error near >\n");
		return (1);
	}
	attr->token = -1;
	attr->last_operator = 6;
	return (0);
}
