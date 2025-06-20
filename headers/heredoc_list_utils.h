/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_list_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:36:11 by ebini             #+#    #+#             */
/*   Updated: 2025/06/15 02:12:36 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_LIST_UTILS_H
# define HEREDOC_LIST_UTILS_H

# include "defs/hd_node.h"

t_hd_node	*hd_new(int fd);
void		hd_add_front(t_hd_node **lst, t_hd_node *new_node);
void		hd_add_back(t_hd_node **lst, t_hd_node *new_node);
void		hd_move_last(t_hd_node **dest, t_hd_node **src);
int			hd_pop(t_hd_node **lst);
void		hd_clear(t_hd_node **lst);

#endif
