/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 06:57:12 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/21 23:57:35 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "expand.h"
#include "alloc.h"

size_t	strtotab_len(char *str, size_t len)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (i < len)
	{
		if (str[i])
		{
			++size;
			while (str[i])
				++i;
		}
		else
			++i;
	}
	return (size);
}

int	tab_check(char **tab, size_t i)
{
	if (!tab[i])
	{
		while (i > 0)
		{
			--i;
			free(tab[i]);
		}
		free(tab);
		return (1);
	}
	return (0);
}

char	**strtotab(char *str, size_t len)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (smalloc((void **)&tab, (strtotab_len(str, len) + 1) * sizeof(char *)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i])
		{
			tab[j] = ft_strdup(&str[i]);
			if (tab_check(tab, j))
				return (NULL);
			++j;
			while (str[i])
				++i;
		}
		else
			++i;
	}
	tab[j] = NULL;
	free(str);
	return (tab);
}

char	**expand(char *cmd, int status)
{
	char	*tab;
	size_t	len;

	len = expand_len(cmd, status);
	if (smalloc((void **)&tab, (len + 1) * sizeof(char)))
		return (NULL);
	expand_fill(tab, cmd, status);
	return (strtotab(tab, len));
}
