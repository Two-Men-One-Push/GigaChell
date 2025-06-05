/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:43:13 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 19:18:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stddef.h>
#include "print.h"

int	syntax_and(t_syntax_attr *attr, size_t *index)
{
	if (attr->token <= 0)
		return (swrite(2, "minishell: syntax error near &&\n", 33, 2));
	attr->last_operator = 1;
	attr->token = 0;
	++*index;
	return (0);
}
