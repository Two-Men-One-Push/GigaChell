/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piped_cmd_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:46:52 by ebini             #+#    #+#             */
/*   Updated: 2025/07/12 11:35:52 by CyberOneFR       ###   ########.fr       */
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

static int	handle_child_exec(char **argv)
{
	int		builtin_result;

	if (start_builtin(argv, (t_redirect_fd[]){{STDIN_FILENO, STDOUT_FILENO}},
		&builtin_result))
		return (bin_exec(argv));
	return (builtin_result);
}

int	piped_cmd_exec(char *cmd, int last_status, t_pipe_fd *pipe_fd,
	t_hd_node **heredoc_list)
{
	t_redirect_fd	redirect;
	char			**argv;
	int				child_result;

	redirect = (t_redirect_fd){pipe_fd->in, pipe_fd->out};
	if (pipe_fd->next_in >= 0)
		secure_close(pipe_fd->next_in);
	if (get_redirection(cmd, &redirect, heredoc_list))
		return (-1);
	if (apply_redirection(&redirect))
		return (-1);
	argv = expand(cmd, last_status);
	if (!argv || !*argv)
	{
		if (!argv)
			return (-1);
		return (0);
	}
	child_result = handle_child_exec(argv);
	free_split(argv);
	return (child_result);
}
