/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:06:39 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 17:26:00 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expand.h"
#include "libft.h"
#include "identifier.h"
#include "env.h"
#include <stdio.h>
#include "utils.h"

size_t	expand_var_len(char **cmd, int status)
{
	size_t	len;
	char	buf[12];
	char	*str;

	if (*++(*cmd) == '?')
	{
		++(*cmd);
		str = bitoa(buf, status);
		len = ft_strlen(str);
		return (len);
	}
	len = ft_strlen(ft_getenv((*cmd)));
	while (is_var_char(*(*cmd + 1)))
		++(*cmd);
	return (len);
}

size_t	expand_len(char *cmd, int status)
{
	size_t	len;
	int		dquote;
	int		squote;

	--cmd;
	len = 0;
	dquote = 0;
	squote = 0;
	while (*++cmd)
	{
		if (!squote && *cmd == '$' && (is_var_start(cmd[1]) || cmd[1] == '?'))
			len += expand_var_len(&cmd, status);
		else if (!dquote && *cmd == '\'')
			squote = !squote;
		else if (!squote && *cmd == '\"')
			dquote = !dquote;
		else
			++len;
	}
	return (len);
}

void	expand_var_fill(char **tab, char **cmd, int dquote, int status)
{
	char	*var;
	char	buf[12];
	char	*str;
	int		i;

	i = -1;
	if (*++(*cmd) == '?')
	{
		++(*cmd);
		str = bitoa(buf, status);
		while (str[++i])
			*++(*tab) = str[i];
		return ;
	}
	var = ft_getenv((*cmd));
	while (is_var_char(*(*cmd + 1)))
		++(*cmd);
	while (*var)
	{
		if (!dquote && (*var == ' ' || *var == '	'))
			*++(*tab) = '\0';
		else
			*++(*tab) = *var;
		++var;
	}
}

void	expand_fill(char *tab, char *cmd, int status)
{
	t_quote	quote;

	--cmd;
	--tab;
	quote = (t_quote){0, 0};
	while (*++cmd)
	{
		if (!quote.sq && *cmd == '$' && (is_var_start(cmd[1]) || cmd[1] == '?'))
			expand_var_fill(&tab, &cmd, quote.dq, status);
		else if (!quote.dq && *cmd == '\'')
			quote.sq = !quote.sq;
		else if (!quote.sq && *cmd == '\"')
			quote.dq = !quote.dq;
		else if (!quote.sq && !quote.dq && (*cmd == ' ' || *cmd == '	'))
			*++tab = '\0';
		else
			*++tab = *cmd;
	}
	*++tab = '\0';
}
