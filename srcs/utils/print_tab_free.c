/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:48:55 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/20 02:50:12 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void	print_tab_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		printf("arg%zu : '%s'\n", i, tab[i]);
		free(tab[i]);
		++i;
	}
	free(tab);
}
