/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 04:23:46 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 05:01:24 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "tchain.h"
#include "tstring.h"
#include <unistd.h>
#include "libft.h"
#include "identifier.h"
#include "env.h"

char	*extract(char *src, size_t size)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (src[i] && i < size)
	{
		dest[j] = src[i];
		++j;
		++i;
	}
	dest[j] = '\0';
	return (dest);
}

int	arg_extract(char *cmd, size_t *i, t_chain *chain)
{
	char	*str;

	str = &cmd[*i];
	while (cmd[*i] && cmd[*i] != ' ' && cmd[*i] != '	')
	{
		if (cmd[*i] == '\'' || cmd[*i] == '\"')
			skipto(cmd, i, cmd[*i]);
		++*i;
	}
	str = extract(str, (size_t)(&cmd[*i] - str));
	if (!str)
		return (1);
	if (chain_append(chain, chain_link_new(str)))
		return (1);
	return (0);
}

int	arg_split(t_chain *chain, char *cmd)
{
	size_t	i;

	i = 0;
	*chain = chain_init();
	while (cmd[i])
	{
		if (cmd[i] != ' ' && cmd[i] != '	')
		{
			if (arg_extract(cmd, &i, chain))
				return (1);
		}
		else
			++i;
	}
	return (0);
}
