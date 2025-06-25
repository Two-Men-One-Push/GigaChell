/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gigachell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:25:45 by ebini             #+#    #+#             */
/*   Updated: 2025/06/25 19:11:35 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIGACHELL_H
# define GIGACHELL_H

# include <stdbool.h>
# include <sys/types.h>

# include "defs/hd_node.h"
# include "defs/pipe_fd.h"
# include "defs/redirect_fd.h"

bool	parse_heredoc(char *cmd, t_hd_node **heredoc_list);
int		get_redirection(char *cmd, t_redirect_fd *redirect,
			t_hd_node **heredoc_list);
int		apply_redirection(t_redirect_fd *redirect);

int		logic_exec(char *cmd, int last_status, t_hd_node **heredoc_list);
int		pipe_exec(char *cmd, int last_status, t_hd_node **heredoc_list);
pid_t	handle_piped_cmd(char *cmd, int last_satus, t_pipe_fd pipe_fd,
			t_hd_node **heredoc_list);
pid_t	subshell_exec(char *cmd, int last_satus, t_redirect_fd *redirect,
			t_hd_node **heredoc_list);

#endif
