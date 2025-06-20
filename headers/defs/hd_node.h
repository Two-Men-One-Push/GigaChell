/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_node.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:33:51 by ebini             #+#    #+#             */
/*   Updated: 2025/06/14 21:09:09 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_NODE_H
# define HD_NODE_H

typedef struct s_hd_node
{
	int					fd;
	struct s_hd_node	*next;
}			t_hd_node;

#endif
