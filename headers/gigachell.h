/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gigachell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:25:45 by ebini             #+#    #+#             */
/*   Updated: 2025/07/17 16:48:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIGACHELL_H
# define GIGACHELL_H

# include "syntax.h"
# include "defs/hd_node.h"
# include "defs/pipe_fd.h"
# include "defs/redirect_fd.h"
# include "defs/result.h"
# include "syntax.h"
# include <stdbool.h>
# include <sys/types.h>

int				parse_heredoc(char *cmd, t_hd_node **heredoc_list);
int				get_redirection(char *cmd, t_redirect_fd *redirect,
					t_hd_node **heredoc_list);
int				apply_redirection(t_redirect_fd *redirect);

int				logic_exec(char *cmd, int last_status,
					t_hd_node **heredoc_list);
int				pipe_exec(char *cmd, int last_status, t_hd_node **heredoc_list);
t_pipe_result	handle_piped_segment(char *cmd, int last_satus,
					t_pipe_fd *pipe_fd, t_hd_node **heredoc_list);
t_pipe_result	subshell_exec(char *cmd, int last_satus, t_pipe_fd *pipe_fd,
					t_hd_node **heredoc_list);
int				piped_cmd_exec(char *cmd, int last_status, t_pipe_fd *pipe_fd,
					t_hd_node **heredoc_list);
t_pipe_result	neutral_cmd_exec(char *cmd, int last_status,
					t_hd_node **heredoc_list);
int				bin_exec(char **cmd);

#endif
