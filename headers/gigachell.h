/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gigachell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/06/05 19:10:38 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GIGACHELL_H
# define GIGACHELL_H

# include <stdbool.h>

# include "heredoc_list_utils.h"
# include "syntax.h"

bool	parse_heredoc(char *cmd, t_hd_node **heredoc_list);

int		logic_exec(int last_status, char *cmd, t_hd_node **heredoc_list);
int		pipe_exec(int last_status, char *cmd, t_hd_node **heredoc_list);

#endif
