/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 06:57:12 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/16 15:22:49 by ethebaul         ###   ########.fr       */
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

	i = 0;
	len = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$' && is_var_start(cmd[i + 1]))
		{
			len += ft_strlen(ft_getenv(&cmd[i]));
			while (is_var_char(cmd[++i]))
				++i;
		}
		if (cmd[i] != '\'' && cmd[i] != '\"')
		{
			++len;
			++i;
		}
	}
	return (len);
}

char	**expand(char *cmd)
{
	printf("%zu\n", expand_len(cmd));
	return (NULL);
}
