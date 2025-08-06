/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:20:11 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/06 14:10:49 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "syntax.h"
#include <stdio.h>

int	syntax_token(t_syntax_attr *attr, char *str, size_t *index)
{
	int		i;

	i = 0;
	if (!(str[*index] == '\t' || str[*index] == ' '))
	{
		if (attr->token == 2)
		{
			while (str[*index + i] && !(str[*index + i] == '\t'
					|| str[*index + i] == ' '))
				++i;
			str[*index + i] = '\0';
			printf("minishell: syntax error near '%s'\n", &str[*index]);
			return (1);
		}
		attr->token = 1;
	}
	return (0);
}

int	syntax_operator(t_syntax_attr *attr, char *str, size_t *index)
{
	if (str[*index] == '\"')
		return (syntax_dquote(attr, str, index));
	else if (str[*index] == '\'')
		return (syntax_squote(attr, str, index));
	else if (str[*index] == '(')
		return (syntax_open(attr));
	else if (str[*index] == ')')
		return (syntax_close(attr));
	else if (str[*index] == '&' && str[*index + 1] == '&')
		return (syntax_and(attr, index));
	else if (str[*index] == '|' && str[*index + 1] == '|')
		return (syntax_or(attr, index));
	else if (str[*index] == '|')
		return (syntax_pipe(attr));
	else if (str[*index] == '<' && str[*index + 1] == '<')
		return (syntax_heredoc(attr, index));
	else if (str[*index] == '<')
		return (syntax_in(attr));
	else if (str[*index] == '>' && str[*index + 1] == '>')
		return (syntax_append(attr, index));
	else if (str[*index] == '>')
		return (syntax_out(attr));
	else
		return (syntax_token(attr, str, index));
	return (0);
}
