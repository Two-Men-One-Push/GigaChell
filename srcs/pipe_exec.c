/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:48:19 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 01:49:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs/hd_node.h"
#include "utils.h"
#include "defs/pipe_fd.h"

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

int	pipe_exec(char *cmd, t_hd_node *heredoc_list)
{
	t_pipe_fd	pipe_fd;
	int			status;
	size_t		i;

	i = 0;
	while (cmd[i])
	{
		offset_to_operator(cmd, &i);
		if (cmd[i])
		{
			i += 1;
		}
	}
	return (status);
}
