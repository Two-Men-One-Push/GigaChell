/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:48:19 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 01:56:34 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs/hd_node.h"
#include "utils.h"

#include <stdio.h>

static void	skip_to_operator(char *cmd, size_t *i)
{
	while (cmd[*i])
	{
		if (cmd[*i] == '\'')
			skip_squote(cmd, i);
		else if (cmd[*i] == '"')
			skip_dquote(cmd, i);
		else if (cmd[*i] == '(')
			skip_paranthesis(cmd, i);
		else if ((cmd[*i] == '&' && cmd[*i + 1] == '&') || (cmd[*i] == '|'
				&& cmd[*i + 1] == '|'))
			return ;
		else
			++*i;
	}
}

static void	clear_to_operator(char *cmd, size_t *i, t_hd_node **heredoc_list)
{
	while (cmd[*i])
	{
		if (cmd[*i] == '\'')
			skip_squote(cmd, i);
		else if (cmd[*i] == '"')
			skip_dquote(cmd, i);
		else if (cmd[*i] == '(')
			clear_paranthesis(cmd, i, heredoc_list);
		else if ((cmd[*i] == '&' && cmd[*i + 1] == '&')
			|| (cmd[*i] == '|' && cmd[*i + 1] == '|'))
		{
			++*i;
			return ;
		}
		else
			++*i;
	}
}

/**
 * @return true if the end of the command is reached without finding any
 * compatible logic operator, false if a one is found.
 * (a compatible logic operator is && if status code is 0 and || otherwise)
 */
bool	handle_status(int status, char *cmd, size_t *i, t_hd_node **heredoc_list)
{
	++*i;
	while (cmd[*i])
	{
		if (!status && cmd[*i] == '&')
		{
			++*i;
			return (0);
		}
		if (status && cmd[*i] == '|')
		{
			++*i;
			return (0);
		}
		clear_to_operator(cmd, i, heredoc_list);
	}
	return (1);
}

int	logic_exec(char *cmd, t_hd_node *heredoc_list)
{
	int		status;
	size_t	i;

	status = 0;
	i = 0;
	while (cmd[i])
	{
		skip_to_operator(cmd, &i);
		if (!cmd[i])
		{
			printf("%s\n", cmd);
			return (0);
			// return (exec_pipe(cmd, heredoc_list));
		}
			// status = exec_pipe(str_extract(cmd, i), heredoc_list); // "echo test && echo coucou" will become "echo test \0& echo coucou"
			status = 0;
			printf("%s\n", str_extract(cmd, i));
		if (handle_status(status, cmd, &i, &heredoc_list))
			return (status);
		cmd += i;
		i = 0;
	}
	return (status);
}
