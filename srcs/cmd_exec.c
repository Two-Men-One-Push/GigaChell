/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:58:05 by ebini             #+#    #+#             */
/*   Updated: 2025/06/02 18:17:21 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "defs/hd_node.h"
#include "defs/redirect_fd.h"
#include "defs/pipe_fd.h"
#include "identifier.h"
#include "utils.h"

pid_t	handle_paranthesis(char *cmd, int last_status, t_redirect_fd *redirect,
	t_hd_node *heredoc_list)
{
	size_t	i;
	char	*sub_cmd_start;
	char	*sub_cmd_len;

	sub_cmd_start = cmd + 1;
	i = 0;
	skip_paranthesis(cmd, &i);
	sub_cmd_len = i - 2;
	while (cmd[i])
	{
		
		++i;
	}
}

pid_t	cmd_exec(char *cmd, int last_satus, t_pipe_fd pipe_fd,
	t_hd_node *heredoc_list)
{
	size_t			i;
	t_redirect_fd	redirect;

	redirect = (t_redirect_fd){pipe_fd.in, pipe_fd.out, -1};
	i = -1;
	while (is_space(cmd[++i]))
		;
	if (cmd[i] == '(')
		
}
