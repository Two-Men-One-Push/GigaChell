/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gigachell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:25:45 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 22:35:44 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIGACHELL_H
# define GIGACHELL_H

# include <stdbool.h>

# include "heredoc_list_utils.h"

int		check_syntaxe(char *cmd);

bool	parse_heredoc(char *cmd, t_hd_node **heredoc_list);

int		logic_exec(char *cmd, t_hd_node *heredoc_list);
int		pipe_exec(char *cmd, t_hd_node *heredoc_list);

#endif
