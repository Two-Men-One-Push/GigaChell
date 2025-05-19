/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:45:21 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 22:47:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "defs/hd_node.h"
#include "utils.h"

#include <stdio.h>

void	hd_clear(t_hd_node **lst)
{
	t_hd_node	*next;

	
	if (!*lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		secure_close((*lst)->fd);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
