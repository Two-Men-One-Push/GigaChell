/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 04:01:08 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 04:12:31 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tchain.h"
#include <stdlib.h>

void	chain_free(t_chain *chain)
{
	t_chain_link	*tmp;

	while (chain->start)
	{
		tmp = chain->start;
		chain->start = chain->start->next;
		free(tmp->data);
		free(tmp);
	}
}
