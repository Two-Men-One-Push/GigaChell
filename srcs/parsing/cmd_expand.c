/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 06:57:12 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/10 09:26:33 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**cmd_expand(char *cmd)
{
	// char	**tab;
	int		size;
	int		i;

	i = -1;
	size = 0;
	while (cmd[++i])
	{
		if (cmd[i] == ' ' || cmd[i] == '\t')
			continue ;
		++size;
		while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
			++i;
	}
	return ((char **)0);
}
