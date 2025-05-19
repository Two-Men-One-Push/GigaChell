/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:16:12 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 01:49:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "defs/hd_node.h"

t_hd_node	*hd_new(int fd)
{
	t_hd_node	*new_lst;

	new_lst = malloc(sizeof(t_hd_node));
	if (!new_lst)
		return (NULL);
	new_lst->fd = fd;
	new_lst->next = NULL;
	return (new_lst);
}
