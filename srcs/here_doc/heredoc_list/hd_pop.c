/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 01:49:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "defs/hd_node.h"

int	hd_pop(t_hd_node **lst)
{
	int			fd;
	t_hd_node	*last_node;
	t_hd_node	*parent_node;

	last_node = (*lst)->next;
	if (!last_node)
	{
		fd = (*lst)->fd;
		free(*lst);
		*lst = NULL;
		return (fd);
	}
	while (last_node->next)
	{
		parent_node = last_node;
		last_node = last_node->next;
	}
	fd = last_node->fd;
	free(last_node);
	parent_node->next = NULL;
	return (fd);
}
