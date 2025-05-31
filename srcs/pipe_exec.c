/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:48:19 by ebini             #+#    #+#             */
/*   Updated: 2025/05/31 20:17:44 by ebini            ###   ########lyon.fr   */
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
		secure_close(pipe_fd->out);
	if (is_last)
	{
		pipe_fd->in = pipe_fd->next_in;
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

static int	error_pipe(void)
{
	while (wait(NULL) >= 0)
		;
	return (-1);
}
/**
 * There are different cases for pid value
 * a positive value is the value of a process's pid.
 * 0 is the return value of a unforked builtin.
 * -1 if an error
 */
static int	exit_pipe(pid_t last_pid, t_pipe_fd *pipe_fd, int last_status)
{
	int	stat_loc;

	if (pipe_fd->in > -1)
		secure_close(pipe_fd->in);
	if (last_pid < 0)
		return (last_status);
	waitpid(last_pid, &stat_loc, 0);
	while (wait(NULL) >= 0)
		;
	if (errno != ECHILD)
		return (-1);
	if (WIFEXITED(stat_loc))
		return (WEXITSTATUS(stat_loc));
	else if (WIFSIGNALED(stat_loc))
		return (WTERMSIG(stat_loc) + 128);
	else
		return (1);
}

int	pipe_exec(int last_status, char *cmd, t_hd_node **heredoc_list)
{
	t_pipe_fd	pipe_fd;
	size_t		i;
	pid_t		last_pid;
	bool		last_cmd;

	pipe_fd = (t_pipe_fd){-1, -1, -1};
	last_pid = -1;
	i = 0;
	printf("%s\n", cmd);
	while (true)
	{
		offset_to_operator(cmd, &i);
		last_cmd = !cmd[i];
		if (swap_pipe(&pipe_fd, !cmd[i]))
			return (error_pipe());
		(void)heredoc_list;
		//cmd_exec(str_extract(cmd, i), &last_status, pipe_fd, heredoc_list)
		(void)last_pid;
		printf("\t(pipe)%d > \"%s\"\n", last_status, str_extract(cmd, i));
		if (last_cmd)
			return (exit_pipe(last_pid, &pipe_fd, last_status));
		cmd += ++i;
		i = 0;
	}
}
