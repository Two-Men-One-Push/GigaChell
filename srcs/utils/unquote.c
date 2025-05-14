/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 05:49:08 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 06:29:57 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"
#include "utils.h"

static void	unquote(char *s)
{
	const char	quote = *s;
	size_t		len;

	len = 0;
	while (s[++len] != quote)
		;
	ft_memmove(s + 1, s, len - 1);
	ft_memmove(s + len + 1, s + len - 1, ft_strlen(s + len + 1) + 1);
}

void	str_unquote(char *s)
{
	char	*quote_position;
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			quote_position = s + i;
			skip_dquote(s, &i);
			i -= 2;
			unquote(quote_position);
		}
		else if (s[i] == '\'')
		{
			quote_position = s + i;
			skip_squote(s, &i);
			i -= 2;
			unquote(quote_position);
		}
		else
			++i;
	}
}
