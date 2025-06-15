/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_piped_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:58:05 by ebini             #+#    #+#             */
/*   Updated: 2025/06/15 02:42:26 by ebini            ###   ########lyon.fr   */
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

#include <stdio.h>

pid_t	handle_piped_cmd(char *cmd, int *last_satus, t_pipe_fd pipe_fd,
	t_hd_node **heredoc_list)
{
	size_t			i;
	t_redirect_fd	redirect;

	redirect = (t_redirect_fd){pipe_fd.in, pipe_fd.out, STDERR_FILENO};
	i = -1;
	while (is_space(cmd[++i]))
		;
	if (cmd[i] == '(')
	{
		paranthesis_exec(cmd, last_satus, &redirect, heredoc_list);
	}
	(void)last_satus;
	(void)pipe_fd;
	(void)heredoc_list;
	printf("	%s\n", cmd);
	return (999);
}
