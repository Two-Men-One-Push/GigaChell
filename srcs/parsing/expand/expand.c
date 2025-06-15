/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 06:57:12 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 04:41:23 by ethebaul         ###   ########.fr       */
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

int	arg_expand(t_chain *chain)
{
	t_chain_link	*link;

	link = chain->start;
	while (link)
	{
		if (expand_var(&link->data))
			return (1);
		if (split_expanded_arg(chain, &link))
			return (1);
		link = link->next;
	}
	return (0);
}

char	**expand(char *cmd)
{
	t_chain	chain;

	if (arg_split(&chain, cmd) || arg_expand(&chain))
	{
		chain_free(&chain);
		return (NULL);
	}
	return (NULL);
}
