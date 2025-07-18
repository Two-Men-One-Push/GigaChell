/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:48:19 by ebini             #+#    #+#             */
/*   Updated: 2025/07/18 06:29:19 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

#include "defs/hd_node.h"
#include "defs/pipe_fd.h"
#include "utils.h"
#include "gigachell.h"

#include <stdlib.h>
#include <string.h>

static void	offset_to_operator(char *cmd, size_t *i)
{
	while (cmd[*i])
	{
		if (cmd[*i] == '\'')
			skip_squote(cmd, i);
		else if (cmd[*i] == '"')
			skip_dquote(cmd, i);
		else if (cmd[*i] == '(')
			skip_paranthesis(cmd, i);
		else if (cmd[*i] == '|')
			return ;
		else
			++*i;
	}
}

static int	swap_pipe(t_pipe_fd *pipe_fd, bool is_last)
{
	int	fd_buffer[2];

	if (pipe_fd->in > -1)
		secure_close(pipe_fd->in);
	if (pipe_fd->out > -1)
	{
		secure_close(pipe_fd->out);
		pipe_fd->out = -1;
	}
	if (is_last)
	{
		pipe_fd->in = pipe_fd->next_in;
		pipe_fd->next_in = -1;
		return (0);
	}
	if (pipe(fd_buffer))
	{
		perror("gigachell: pipe");
		secure_close(pipe_fd->next_in);
		return (-1);
	}
	pipe_fd->in = pipe_fd->next_in;
	pipe_fd->next_in = fd_buffer[0];
	pipe_fd->out = fd_buffer[1];
	return (0);
}

static int	wait_children(t_pipe_result pipe_result)
{
	int		stat_loc;
	pid_t	last_wait_result;

	last_wait_result = waitpid(pipe_result.pid, &stat_loc, 0);
	if (last_wait_result < 0)
		perror("gigachell: waitpid");
	errno = 0;
	while (wait(NULL) >= 0)
		;
	if (errno != ECHILD)
		perror("gigachell: wait");
	if (errno != ECHILD || last_wait_result < 0)
		return (-1);
	if (WIFEXITED(stat_loc))
		return (WEXITSTATUS(stat_loc));
	else if (WIFSIGNALED(stat_loc))
		return (WTERMSIG(stat_loc) + 128);
	else
		return (1);
}

static int	exit_pipe(t_pipe_result pipe_result, t_pipe_fd *pipe_fd,
	int last_status)
{
	if (pipe_result.type == PROC_BUILTIN)
		return (pipe_result.status);
	if (pipe_result.type == PROC_FORK)
	{
		if (pipe_result.status >= 0)
			return (-pipe_result.status - 3);
		return (pipe_result.status);
	}
	if (pipe_fd->in > -1)
		secure_close(pipe_fd->in);
	if (pipe_result.pid < 0)
		return (last_status);
	return (wait_children(pipe_result));
}

int	pipe_exec(char *cmd, int last_status, t_hd_node **heredoc_list)
{
	t_pipe_fd		pipe_fd;
	size_t			i;
	t_pipe_result	pipe_result;
	bool			last_cmd;

	pipe_fd = (t_pipe_fd){-1, -1, -1};
	i = 0;
	while (true)
	{
		offset_to_operator(cmd, &i);
		last_cmd = !cmd[i];
		if (swap_pipe(&pipe_fd, last_cmd))
		{
			while (wait(NULL) >= 0)
				;
			return (-1);
		}
		pipe_result = handle_piped_segment(str_extract(cmd, i), last_status,
				&pipe_fd, heredoc_list);
		if (last_cmd || pipe_result.type == PROC_FORK)
			return (exit_pipe(pipe_result, &pipe_fd, last_status));
		cmd += ++i;
		i = 0;
	}
}
