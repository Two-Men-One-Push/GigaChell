/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:53:01 by ebini             #+#    #+#             */
/*   Updated: 2025/06/14 23:26:44 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "heredoc_list_utils.h"
#include "libft.h"

void	hd_move_last(t_hd_node **dest, t_hd_node **src)
{
	t_hd_node	**last_node;

	last_node = src;
	while ((*last_node)->next)
		last_node = &((*last_node)->next);
	hd_add_front(dest, *last_node);
	*last_node = NULL;
}
