/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_link_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 02:05:06 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 03:56:40 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tchain.h"
#include <stdlib.h>

t_chain_link	*chain_link_new(void *data)
{
	t_chain_link	*new_chain_link;

	new_chain_link = malloc(sizeof(t_chain_link));
	if (!new_chain_link)
		return (NULL);
	*new_chain_link = chain_link_init(data);
	return (new_chain_link);
}
