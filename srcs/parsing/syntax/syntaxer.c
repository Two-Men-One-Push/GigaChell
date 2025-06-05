/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 05:42:55 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 19:20:20 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstring.h"
#include "syntax.h"
#include "print.h"

int	syntaxer(t_string	string)
{
	t_syntax_attr	attr;
	size_t			index;

	index = 0;
	attr = (t_syntax_attr){0, 0, 0};
	while (index < string.size)
	{
		if (syntax_operator(&attr, string, &index))
			return (2);
		++index;
	}
	if (syntax_error(attr))
		return (2);
	return (0);
}

int	syntax_error(t_syntax_attr attr)
{
	if (attr.token <= 0 && attr.last_operator == 1)
		return (swrite(2, "minishell: syntax error near &&\n", 33, 2));
	if (attr.token <= 0 && attr.last_operator == 2)
		return (swrite(2, "minishell: syntax error near ||\n", 33, 2));
	if (attr.token <= 0 && attr.last_operator == 3)
		return (swrite(2, "minishell: syntax error near |\n", 32, 2));
	if (attr.token <= 0 && attr.last_operator == 4)
		return (swrite(2, "minishell: syntax error near <\n", 32, 2));
	if (attr.token <= 0 && attr.last_operator == 5)
		return (swrite(2, "minishell: syntax error near <<\n", 33, 2));
	if (attr.token <= 0 && attr.last_operator == 6)
		return (swrite(2, "minishell: syntax error near >\n", 32, 2));
	if (attr.token <= 0 && attr.last_operator == 7)
		return (swrite(2, "minishell: syntax error near >>\n", 33, 2));
	if (attr.scope_depth < 0)
		return (swrite(2, "minishell: syntax error near )\n", 32, 2));
	if (attr.scope_depth > 0)
		return (swrite(2, "minishell: syntax error near (\n", 32, 2));
	return (0);
}
