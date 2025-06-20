/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_link_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 02:03:35 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 02:04:53 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tchain.h"

t_chain_link	chain_link_init(void *data)
{
	t_chain_link	chain_link;

	chain_link.data = data;
	chain_link.next = NULL;
	chain_link.prev = NULL;
	return (chain_link);
}
