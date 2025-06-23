/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:18:03 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 03:57:10 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tchain.h"

int	chain_append(t_chain *chain, t_chain_link *link)
{
	if (!link)
		return (1);
	if (chain->size == 0)
	{
		chain->start = link;
		chain->end = link;
	}
	else
	{
		chain->end->next = link;
		link->prev = chain->end;
		chain->end = link;
	}
	++chain->size;
	return (0);
}
