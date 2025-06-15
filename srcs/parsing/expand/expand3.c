/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 04:41:25 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 05:02:46 by ethebaul         ###   ########.fr       */
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

void	get_var(char *src, char *dest, size_t *j)
{
	size_t	k;

	k = 0;
	while (src[k])
	{
		dest[*j] = src[k];
		++*j;
		++k;
	}
}

void	var_dump(char *src, char *dest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == '\'')
			++i;
		else if (src[i] == '$')
			get_var(ft_getenv(src[i + 1]), dest, &j);
		else
		{
			dest[j] = src[i];
			++i;
			++j;
		}
	}
}

int	expand_var(char **str)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len += ft_strlen(*str);
	i = 0;
	while ((*str)[i])
		if ((*str)[i] == '$')
			len += ft_strlen(ft_getenv((*str)[i + 1]));
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (1);
	var_dump(*str, new_str);
	free(*str);
	*str = new_str;
	return (0);
}

int	split_expanded_arg(t_chain *chain, t_chain_link *link)
{
	t_chain_link	new;
	size_t			i;
	char			*str;
	char			*tmp;

	i = 0;
	str = link->data;
	tmp = str;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '	')
		{
			while (str[i] != ' ' && str[i] != '	')
			{
			}
			tmp = ft_strndup(tmp, &str[i] - tmp);
		}
		++i;
	}
	return (0);
}
