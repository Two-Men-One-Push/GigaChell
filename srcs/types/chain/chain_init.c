/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:16:09 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 01:17:14 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tchain.h"

t_chain	chain_init(void)
{
	t_chain	chain;

	chain.start = NULL;
	chain.end = NULL;
	chain.size = 0;
	return (chain);
}
