/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_limiter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 06:16:34 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 22:30:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "utils.h"
#include "identifier.h"
#include "libft.h"

static bool	is_limiter_char(char c)
{
	return (!(c == ' ' || c == '\t' || c == '&' || c == '|'
		|| c == '<' || c == '>' || c == '(' || c == ')'));
}

char	*get_limiter(char *cmd, size_t *i)
{
	size_t	limiter_len;
	char	*limiter;

	while (is_space(cmd[*i]))
		++*i;
	limiter_len = 0;
	while (cmd[*i + limiter_len] && is_limiter_char(cmd[*i + limiter_len]))
	{
		if (cmd[*i + limiter_len] == '"')
			skip_dquote(cmd + *i, &limiter_len);
		else if (cmd[*i + limiter_len] == '\'')
			skip_squote(cmd + *i, &limiter_len);
		else if (cmd[*i + limiter_len] == '(')
		{
			skip_paranthesis(cmd + *i, &limiter_len);
			printf("char after par: '%c'\n", cmd[*i + limiter_len]);
		}
		else
			++limiter_len;
	}
	limiter = ft_strndup(cmd + *i, limiter_len);
	if (!limiter)
		perror("gigachell: get_limiter");
	str_unquote(limiter);
	*i += limiter_len;
	return (limiter);
}
