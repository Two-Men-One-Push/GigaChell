/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:06:39 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/25 19:49:12 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "identifier.h"
#include "env.h"
#include <stdio.h>

size_t	expand_var_len(char **cmd, int status)
{
	size_t	len;
	char	*str;

	if (*++(*cmd) == '?')
	{
		++(*cmd);
		str = ft_itoa(status);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	len = ft_strlen(ft_getenv(++(*cmd)));
	while (is_var_char(*(*cmd)))
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
		if (!dquote && *cmd == '\'')
			squote = !squote;
		else if (!squote && *cmd == '\"')
			dquote = !dquote;
		else
			++len;
		if (*cmd == '\0')
			break ;
	}
	return (len);
}

void	expand_var_fill(char **tab, char **cmd, int dquote, int status)
{
	char	*var;
	char	*str;
	int		i;

	i = -1;
	if (*++(*cmd) == '?')
	{
		++(*cmd);
		str = ft_itoa(status);
		while (str[++i])
			*++(*tab) = str[i];
		free(str);
		return ;
	}
	var = ft_getenv(++(*cmd));
	while (is_var_char(*(*cmd)))
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
	int		dquote;
	int		squote;

	--cmd;
	--tab;
	dquote = 0;
	squote = 0;
	while (*++cmd)
	{
		if (!squote && *cmd == '$' && (is_var_start(cmd[1]) || cmd[1] == '?'))
			expand_var_fill(&tab, &cmd, dquote, status);
		if (!dquote && *cmd == '\'')
			squote = !squote;
		else if (!squote && *cmd == '\"')
			dquote = !dquote;
		else if (!squote && !dquote && (*cmd == ' ' || *cmd == '	'))
			*++tab = '\0';
		else
			*++tab = *cmd;
		if (*cmd == '\0')
			return ;
	}
	*++tab = '\0';
}
