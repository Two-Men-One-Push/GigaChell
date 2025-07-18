/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/07/17 17:36:14 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "defs/hd_node.h"
#include "defs/configs.h"
#include "env.h"
#include "gigachell.h"
#include "libft.h"
#include "syntax.h"
#include "signal_handling.h"

static int	run_command(char *line, int last_status)
{
	t_hd_node	*heredoc_list;
	int			heredoc_result;

	if (syntaxer(line))
		return (2);
	heredoc_list = NULL;
	heredoc_result = parse_heredoc(line, &heredoc_list);
	if (heredoc_result)
	{
		if (heredoc_result == -2)
			return (130);
		return (-1);
	}
	last_status = logic_exec(line, last_status, &heredoc_list);
	return (last_status);
}

static int	get_exit_status(int old_status, int new_status)
{
	if (new_status == -1)
		return (1);
	if (new_status == -2)
		return (old_status);
	return (-(new_status + 3));
}

static int	main_loop(void)
{
	int		old_status;
	int		new_status;
	char	*line;

	old_status = 0;
	while (true)
	{
		handling_prompt_signal();
		line = readline(GIGACHELL_PROMPT);
		handling_execution_signal();
		if (!line)
			return (old_status);
		if (!*line)
		{
			free(line);
			continue ;
		}
		add_history(line);
		new_status = run_command(line, old_status);
		free(line);
		if (new_status < 0)
			return (get_exit_status(old_status, new_status));
		old_status = new_status;
	}
}

int	main(int ac, char **av, char **envp)
{
	int		status;

	(void)av;
	(void)ac;
	if (ft_initenv(envp))
	{
		perror("gigachell: ft_initenv");
		return (1);
	}
	status = main_loop();
	rl_clear_history();
	ft_clearenv();
	return (status);
}
