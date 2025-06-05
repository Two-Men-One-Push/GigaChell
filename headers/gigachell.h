/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gigachell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:25:45 by ebini             #+#    #+#             */
/*   Updated: 2025/06/06 00:04:15 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef GIGACHELL_H
# define GIGACHELL_H

# include <stdbool.h>
# include <sys/types.h>

# include "syntax.h"
# include "defs/hd_node.h"
# include "defs/pipe_fd.h"

bool	parse_heredoc(char *cmd, t_hd_node **heredoc_list);

int		logic_exec(int last_status, char *cmd, t_hd_node **heredoc_list);
int		pipe_exec(int last_status, char *cmd, t_hd_node **heredoc_list);
pid_t	cmd_exec(char *cmd, int last_satus, t_pipe_fd pipe_fd,
	t_hd_node *heredoc_list);

#endif
