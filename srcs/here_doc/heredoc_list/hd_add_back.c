/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:32:20 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 01:49:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs/hd_node.h"

void	hd_add_back(t_hd_node **lst, t_hd_node *new_node)
{
	if (!new_node)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		return ;
	}
	while ((*lst)->next)
		(lst) = &((*lst)->next);
	(*lst)->next = new_node;
}
