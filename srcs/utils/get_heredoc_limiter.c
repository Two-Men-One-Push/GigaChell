/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_limiter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 06:16:34 by ebini             #+#    #+#             */
/*   Updated: 2025/06/06 19:19:27 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "utils.h"
#include "identifier.h"
#include "libft.h"

char	*get_limiter(char *cmd, size_t *i)
{
	size_t	lim_len;
	char	*limiter;
	char	*lim_start;

	while (is_space(cmd[*i]))
		++*i;
	lim_start = cmd + *i;
	lim_len = 0;
	while (lim_start[lim_len] && is_limiter_char(lim_start[lim_len]))
	{
		if (lim_start[lim_len] == '"')
			skip_dquote(lim_start, &lim_len);
		else if (lim_start[lim_len] == '\'')
			skip_squote(lim_start, &lim_len);
		else if (lim_start[lim_len] == '(')
			skip_paranthesis(lim_start, &lim_len);
		else
			++lim_len;
	}
	limiter = ft_strndup(lim_start, lim_len);
	if (!limiter)
		perror("gigachell: get_limiter");
	str_unquote(limiter);
	*i += lim_len;
	return (limiter);
}
