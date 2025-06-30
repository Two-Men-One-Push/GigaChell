/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 16:41:18 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "env.h"
#include "gigachell.h"
#include "hd_node.h"
#include "libft.h"
#include "configs.h"
#include "syntax.h"
#include "utils.h"
#include "expand.h"

int	run_command(char *line, int last_status)
{
	char		*cmd;
	t_hd_node	*heredoc_list;

	if (syntaxer(ftstring(line, ft_strlen(line))))
	{
		add_history(line);
		return (2);
	}
	cmd = ft_strdup(line);
	if (!cmd)
	{
		perror("gigachell: strdup");
		return (-2);
	}
	heredoc_list = NULL;
	if (parse_heredoc(cmd, &heredoc_list))
	{
		free(cmd);
		return (-1);
	}
	last_status = logic_exec(line, last_status, &heredoc_list);
	add_history(cmd);
	free(cmd);
	return (last_status);
}

int	main_loop(void)
{
	int		old_status;
	int		new_status;
	char	*line;

	old_status = 0;
	while (true)
	{
		line = readline(GIGACHELL_PROMPT);
		if (!line)
			return (old_status);
		if (!*line)
		{
			free(line);
			continue ;
		}
		new_status = run_command(line, old_status);
		free(line);
		if (new_status < -2)
			return (-(new_status + 3));
		if (new_status == -2)
			return (old_status);
		if (new_status == -1)
			return (1);
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
