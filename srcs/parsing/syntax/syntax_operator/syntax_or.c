/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:49:30 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/10 09:25:19 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stddef.h>
#include <unistd.h>

int	syntax_or(t_syntax_attr *attr, size_t *index)
{
	if (attr->token <= 0)
		return (write(2, "minishell: syntax error near ||\n", 33));
	attr->last_operator = 2;
	attr->token = 0;
	++*index;
	return (0);
}
