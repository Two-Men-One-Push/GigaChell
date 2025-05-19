/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:33:51 by ebini             #+#    #+#             */
/*   Updated: 2025/05/12 06:53:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_LIST_H
# define HEREDOC_LIST_H

typedef struct s_hd_node
{
	int					fd;
	struct s_hd_node	*next;
}			t_hd_node;

#endif
