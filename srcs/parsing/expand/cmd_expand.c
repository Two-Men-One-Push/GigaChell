/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 06:57:12 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/10 09:43:47 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expand.h"
#include <stdio.h>

char	**cmd_expand(char *cmd)
{
	char	**tab;
	int		size;

	size = count_args(cmd);
	tab = (char **)malloc((size + 1) * sizeof(char *));
	if (!tab)
	{
		perror("gigachell");
		return (NULL);
	}
	tab[size] = NULL;
	// while ()
	// {
		
	// }
	return (tab);
}
