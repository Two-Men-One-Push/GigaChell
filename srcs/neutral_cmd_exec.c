/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neutral_cmd_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:37:03 by ebini             #+#    #+#             */
/*   Updated: 2025/07/14 23:20:21 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#include "defs/redirect_fd.h"
#include "builtins.h"
#include "gigachell.h"
#include "utils.h"
#include "libft.h"
#include "expand.h"
#include "signal_handling.h"

static t_pipe_result	handle_bin_exec(char **argv, t_redirect_fd *redirect)
{
	pid_t	pid;

	pid = fork();
	if (pid)
	{
		clear_redirect(redirect);
		return ((t_pipe_result){.type = PROC_MAIN, .pid = 0});
	}
	if (handling_child_signal())
		return ((t_pipe_result){.type = PROC_FORK, .status = -1});
	if (apply_redirection(redirect))
		return ((t_pipe_result){.type = PROC_FORK, .status = -1});
	return ((t_pipe_result){.type = PROC_FORK, .status = bin_exec(argv)});
}

t_pipe_result	neutral_cmd_exec(char *cmd, int last_status,
	t_hd_node **heredoc_list)
{
	int				builtin_result;
	t_redirect_fd	redirect;
	t_pipe_result	result;
	char			**argv;

	redirect = (t_redirect_fd){-1, -1};
	if (get_redirection(cmd, &redirect, heredoc_list))
		return ((t_pipe_result){.type = PROC_MAIN, .pid = -1});
	argv = expand(cmd, last_status);
	if (!argv || !*argv)
	{
		clear_redirect(&redirect);
		if (!argv)
			return ((t_pipe_result){.type = PROC_MAIN, .pid = -1});
		free(argv);
		return ((t_pipe_result){.type = PROC_BUILTIN, .status = 0});
	}
	if (!start_builtin(argv, &redirect, &builtin_result))
	{
		free_split(argv);
		clear_redirect(&redirect);
		return ((t_pipe_result){.type = PROC_BUILTIN, .status = builtin_result});
	}
	result = handle_bin_exec(argv, &redirect);
	free_split(argv);
	return (result);
}
