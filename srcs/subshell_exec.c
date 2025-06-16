/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:39:50 by ebini             #+#    #+#             */
/*   Updated: 2025/06/15 09:01:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "defs/hd_node.h"
#include "defs/redirect_fd.h"
#include "defs/pipe_fd.h"
#include "gigachell.h"
#include "heredoc_list_utils.h"
#include "utils.h"

pid_t	handle_subprocess_child(char *cmd, int last_satus,
	t_redirect_fd *redirect, t_hd_node **subshell_heredoc_list)
{
	if (apply_redirection(redirect))
		return (-1);
	return (logic_exec(cmd, last_satus, subshell_heredoc_list));
}

int	get_subshell_heredoc_list(char *s, size_t *i,
	t_hd_node **subshell_heredoc_list, t_hd_node **heredoc_list)
{
	size_t	depth;

	depth = 1;
	++*i;
	while (s[*i] && depth)
	{
		if (s[*i] == '"')
			skip_dquote(s, i);
		else if (s[*i] == '\'')
			skip_squote(s, i);
		else if (s[*i] == '<' && s[*i + 1] == '<')
			hd_move_last(subshell_heredoc_list, heredoc_list);
		else
		{
			depth += s[*i] == '(';
			depth -= s[*i] == ')';
			++*i;
		}
	}
	return (!depth);
}

pid_t	exit_subshell_start(t_hd_node **subshell_heredoc_list)
{
	hd_clear(subshell_heredoc_list);
	return (-1);
}

pid_t	subshell_exec(char *cmd, int last_satus, t_redirect_fd *redirect,
	t_hd_node **heredoc_list)
{
	size_t		paranthesis_len;
	t_hd_node	*subshell_heredoc_list;
	pid_t		fork_result;

	subshell_heredoc_list = NULL;
	paranthesis_len = 0;
	get_subshell_heredoc_list(cmd, &paranthesis_len, &subshell_heredoc_list,
		heredoc_list);
	if (get_redirection(cmd + paranthesis_len, redirect, heredoc_list))
		return (exit_subshell_start(&subshell_heredoc_list));
	fork_result = fork();
	if (fork_result == -1)
		return (exit_subshell_start(&subshell_heredoc_list));
	if (fork_result)
	{
		hd_clear(heredoc_list);
		return (handle_subprocess_child(str_extract(cmd + 1, paranthesis_len
					- 2), last_satus, redirect, &subshell_heredoc_list));
	}
	else
	{
		hd_clear(&subshell_heredoc_list);
		return (fork_result);
	}
}
