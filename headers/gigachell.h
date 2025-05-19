/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gigachell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:25:45 by ebini             #+#    #+#             */
/*   Updated: 2025/05/19 09:03:43 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIGACHELL_H
# define GIGACHELL_H

# include <stdbool.h>

# include "heredoc_list_utils.h"
# include "syntax.h"

bool	parse_heredoc(char *cmd, t_hd_node **heredoc_list);

int		logic_exec(char *cmd, t_hd_node *heredoc_list);
int		pipe_exec(char *cmd, t_hd_node *heredoc_list);

#endif
