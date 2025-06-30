/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piped_cmd_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:46:52 by ebini             #+#    #+#             */
/*   Updated: 2025/06/28 06:48:01 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "defs/redirect_fd.h"
#include "builtins.h"
#include "gigachell.h"
#include "parsing/expand.h"
#include "utils.h"
#include "libft.h"

#include <stdio.h>

static int	handle_child_exec(char **cmd)
{
	int		builtin_result;

	if (start_builtin(cmd, (t_redirect_fd[]){{STDIN_FILENO, STDOUT_FILENO}},
		&builtin_result))
		return (bin_exec(cmd));
	return (builtin_result);
}

int	piped_cmd_exec(char *cmd, int last_status, t_pipe_fd *pipe_fd,
	t_hd_node **heredoc_list)
{
	t_redirect_fd	redirect;
	char			**argv;
	int				child_result;

	redirect = (t_redirect_fd){pipe_fd->in, pipe_fd->out};
	if (get_redirection(cmd, &redirect, heredoc_list)
		|| apply_redirection(&redirect))
		return (-1);
	argv = expand(cmd, last_status);
	if (!argv)
	{
		clear_redirect(&redirect);
		return (-1);
	}
	child_result = handle_child_exec(argv);
	free_split(argv);
	return (child_result);
}
