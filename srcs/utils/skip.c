/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:54:47 by ebini             #+#    #+#             */
/*   Updated: 2025/06/15 09:42:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "heredoc.h"
#include "utils.h"

#include <stdio.h>

bool	skip_dquote(char *s, size_t *i)
{
	while (s[++*i] && s[*i] != '"')
		;
	*i += !!s[*i];
	return (s[*i - 1] == '"');
}

bool	skip_squote(char *s, size_t *i)
{
	while (s[++*i] && s[*i] != '\'')
		;
	*i += !!s[*i];
	return (s[*i - 1] == '\'');
}

bool	skip_paranthesis(char *s, size_t *i)
{
	size_t	depth;

	depth = 1;
	++*i;
	while (s[*i] && depth)
	{
		if (s[*i] == '"')
			skip_dquote(s, i);
		else if (s[*i] == '\'')
			skip_squote(s, i);
		else
		{
			depth += s[*i] == '(';
			depth -= s[*i] == ')';
			++*i;
		}
	}
	return (!depth);
}

void	clear_paranthesis(char *s, size_t *i, t_hd_node **heredoc_list)
{
	size_t	depth;

	depth = 1;
	++*i;
	while (depth)
	{
		if (s[*i] == '"')
			skip_dquote(s, i);
		else if (s[*i] == '\'')
			skip_squote(s, i);
		else if (s[*i] == '<' && s[*i + 1] == '<')
			secure_close(hd_pop(heredoc_list));
		else
		{
			depth += s[*i] == '(';
			depth -= s[*i] == ')';
			++*i;
		}
	}
}
