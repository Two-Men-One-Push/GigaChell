/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:02:00 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/10 09:25:02 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include <stddef.h>
#include <unistd.h>

int	syntax_heredoc(t_syntax_attr *attr, size_t *index)
{
	if (attr->token == -1)
		return (write(2, "minishell: syntax error near <<\n", 33));
	attr->last_operator = 5;
	attr->token = -1;
	++*index;
	return (0);
}
