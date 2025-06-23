/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_piped_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:58:05 by ebini             #+#    #+#             */
/*   Updated: 2025/06/23 08:24:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "defs/hd_node.h"
#include "defs/redirect_fd.h"
#include "defs/pipe_fd.h"
#include "identifier.h"
#include "utils.h"
#include "gigachell.h"
#include "expand.h"

#include <stdio.h>

void	close_redirect()
{

}

pid_t	cmd_exec(char *cmd, int last_status, t_redirect_fd *redirect,
	t_hd_node **heredoc_list)
{
	char			**argv;

	if (get_redirection(cmd, redirect, heredoc_list))
		return (-1);
	argv = expand(cmd);
	if (!argv)

}

pid_t	handle_piped_cmd(char *cmd, int last_satus, t_pipe_fd pipe_fd,
	t_hd_node **heredoc_list)
{
	size_t			i;
	t_redirect_fd	redirect;
	pid_t			pid;

	redirect = (t_redirect_fd){pipe_fd.in, pipe_fd.out};
	i = -1;
	while (is_space(cmd[++i]))
		;
	if (cmd[i] == '(')
	{
		pid = subshell_exec(cmd, last_satus, &redirect, heredoc_list);
		if (pid < 0)
			clear_redirect(&redirect);
		return (pid);
	}
	pid = cmd_exec(cmd, last_satus, &redirect, heredoc_list);
	if (pid < 0)
		clear_redirect(&redirect);
	return (pid);
}
