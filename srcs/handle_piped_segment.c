/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_piped_segment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:58:05 by ebini             #+#    #+#             */
/*   Updated: 2025/06/23 08:30:29 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "defs/hd_node.h"
#include "defs/redirect_fd.h"
#include "defs/pipe_fd.h"
#include "defs/result.h"
#include "identifier.h"
#include "utils.h"
#include "gigachell.h"
#include "expand.h"
#include "libft.h"
#include "builtins.h"

#include <stdio.h>

static t_pipe_result	cmd_exec(char *cmd, int last_status, t_pipe_fd *pipe_fd,
	t_hd_node **heredoc_list)
{
	pid_t	pid;

	if (pipe_fd->in < 0 && pipe_fd->out < 0)
		return (neutral_cmd_exec(cmd, last_status, heredoc_list));
	pid = fork();
	if (pid)
		return ((t_pipe_result){.type = RT_MAIN, .pid = pid});
	return ((t_pipe_result){.type = RT_FORK,
			.status = piped_cmd_exec(cmd, last_status, pipe_fd, heredoc_list)});
}

t_pipe_result	handle_piped_segment(char *cmd, int last_satus, t_pipe_fd *pipe_fd,
	t_hd_node **heredoc_list)
{
	while (is_space(*cmd))
		++cmd;
	if (*cmd == '(')
		return (subshell_exec(cmd, last_satus, pipe_fd, heredoc_list));
	return (cmd_exec(cmd, last_satus, pipe_fd, heredoc_list));
}
