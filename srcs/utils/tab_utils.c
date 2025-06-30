/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:48:55 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 18:11:35 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

void	dprint_tab(int fd, char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_dprintf(fd, "%s\n", tab[i]);
		++i;
	}
}
