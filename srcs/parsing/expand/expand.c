/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 06:57:12 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/18 13:37:56 by ethebaul         ###   ########.fr       */
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

size_t	expand_len(char *cmd)
{
	size_t	len;
	size_t	i;
	int		skp;

	i = 0;
	len = 0;
	skp = 1;
	while (cmd[i])
	{
		if (cmd[i] == '$' && is_var_start(cmd[i + 1]))
		{
			len += ft_strlen(ft_getenv(&cmd[i + 1]));
			while (is_var_char(cmd[++i]))
				++i;
		}
		if (cmd[i] == '\"')
			skp = !skp;
		else if (skp && cmd[i] == '\'')
			while (cmd[++i] != '\'')
				++len;
		else
			++len;
		++i;
	}
	return (len);
}

// void	expand_fill(char *tab, char *cmd)
// {
	
// }

char	**expand(char *cmd)
{
	char	*tab;

	printf("%zu\n", expand_len(cmd));
	tab = malloc((expand_len(cmd) + 1) * sizeof(char));
	// expand_fill(tab, cmd);
	return (NULL);
}
