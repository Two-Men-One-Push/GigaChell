/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:39:50 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 02:19:37 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "defs/hd_node.h"
#include "defs/redirect_fd.h"
#include "defs/pipe_fd.h"
#include "defs/result.h"
#include "gigachell.h"
#include "heredoc_list_utils.h"
#include "utils.h"

#include <stdio.h>

static t_pipe_result	handle_subprocess_child(char *cmd, int last_satus,
	t_pipe_fd *pipe_fd, t_hd_node **subshell_heredoc_list)
{
	t_redirect_fd	redirect;
	t_pipe_result	result;
	size_t			paranthesis_len;

	redirect = (t_redirect_fd){pipe_fd->in, pipe_fd->out};
	paranthesis_len = 0;
	skip_paranthesis(cmd, &paranthesis_len);
	if (get_redirection(cmd + paranthesis_len, &redirect,
			subshell_heredoc_list) || apply_redirection(&redirect))
	{
		hd_clear(subshell_heredoc_list);
		return ((t_pipe_result){.type = RT_FORK, .status = -1});
	}
	result.type = RT_FORK;
	result.status = logic_exec(str_extract(cmd + 1, paranthesis_len - 2),
			last_satus, subshell_heredoc_list);
	return (result);
}

static int	get_subshell_heredoc_list(char *cmd,
	t_hd_node **subshell_heredoc_list, t_hd_node **heredoc_list)
{
	size_t	depth;
	size_t	i;

	i = 0;
	*subshell_heredoc_list = NULL;
	depth = 1;
	++i;
	while (depth)
	{
		if (cmd[i] == '"')
			skip_dquote(cmd, &i);
		else if (cmd[i] == '\'')
			skip_squote(cmd, &i);
		else if (cmd[i] == '<' && cmd[++i] == '<')
			hd_move_last(subshell_heredoc_list, heredoc_list);
		else
		{
			depth += cmd[i] == '(';
			depth -= cmd[i] == ')';
			++i;
		}
	}
	return (!depth);
}

t_pipe_result	subshell_exec(char *cmd, int last_satus, t_pipe_fd *pipe_fd,
	t_hd_node **heredoc_list)
{
	t_hd_node	*subshell_heredoc_list;
	pid_t		pid;

	get_subshell_heredoc_list(cmd, &subshell_heredoc_list,
		heredoc_list);
	pid = fork();
	if (pid)
	{
		hd_clear(&subshell_heredoc_list);
		return ((t_pipe_result){.type = RT_MAIN, .pid = pid});
	}
	return (handle_subprocess_child(cmd, last_satus, pipe_fd,
			&subshell_heredoc_list));
}
