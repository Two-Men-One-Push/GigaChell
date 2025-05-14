/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_add_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:30:02 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 01:49:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs/hd_node.h"

void	hd_add_front(t_hd_node **lst, t_hd_node *new_node)
{
	new_node->next = *lst;
	*lst = new_node;
}
