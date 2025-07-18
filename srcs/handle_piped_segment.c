/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_piped_segment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 02:20:21 by ebini             #+#    #+#             */
/*   Updated: 2025/07/18 05:32:03 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "defs/hd_node.h"
#include "defs/pipe_fd.h"
#include "defs/result.h"
#include "identifier.h"
#include "heredoc_list_utils.h"
#include "utils.h"
#include "gigachell.h"
#include "signal_handling.h"

#include <stdio.h>

static void	get_pipe_heredoc_list(char *cmd, t_hd_node **subshell_heredoc_list,
	t_hd_node **heredoc_list)
{
	size_t	i;

	*subshell_heredoc_list = NULL;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '"')
			skip_dquote(cmd, &i);
		else if (cmd[i] == '\'')
			skip_squote(cmd, &i);
		else if (cmd[i] == '<' && cmd[++i] == '<')
			hd_move_last(subshell_heredoc_list, heredoc_list);
		else
			++i;
	}
}

static t_pipe_result	cmd_exec(char *cmd, int last_status, t_pipe_fd *pipe_fd,
	t_hd_node **heredoc_list)
{
	t_hd_node	*pipe_heredoc_list;
	pid_t		pid;

	get_pipe_heredoc_list(cmd, &pipe_heredoc_list, heredoc_list);
	if (pipe_fd->in < 0 && pipe_fd->out < 0)
		return (neutral_cmd_exec(cmd, last_status, &pipe_heredoc_list));
	pid = fork();
	if (pid)
	{
		hd_clear(&pipe_heredoc_list);
		return ((t_pipe_result){.type = PROC_MAIN, .pid = pid});
	}
	hd_clear(heredoc_list);
	handling_child_signal();
	return ((t_pipe_result){.type = PROC_FORK, .status = piped_cmd_exec(cmd,
			last_status, pipe_fd, &pipe_heredoc_list)});
}

t_pipe_result	handle_piped_segment(char *cmd, int last_satus,
	t_pipe_fd *pipe_fd, t_hd_node **heredoc_list)
{
	while (is_space(*cmd))
		++cmd;
	if (*cmd == '(')
		return (subshell_exec(cmd, last_satus, pipe_fd, heredoc_list));
	return (cmd_exec(cmd, last_satus, pipe_fd, heredoc_list));
}
