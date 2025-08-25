/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 07:54:07 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/25 23:53:22 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "ft_glibc.h"
#include "ft_readline.h"
#include "defs/hd_node.h"
#include "defs/configs.h"
#include "env.h"
#include "gigachell.h"
#include "readline_hack.h"
#include "syntax.h"
#include "signal_handling.h"
#include "readline_hack.h"

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
	rl_outstream = stderr;
	while (true)
	{
		handling_prompt_signal();
		line = ft_readline(GIGACHELL_PROMPT);
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

void	breakpoint(void)
{
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_mchunkptr	mchunk;
	int			status;

	(void)av;
	(void)ac;
	mchunk = (t_mchunkptr)((char *)malloc(0x100) - (2 * sizeof(size_t)));
	free((char *)mchunk + (2 * sizeof(size_t)));
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
	{
		write(2, "Error: Use a tty\n", 17);
		return (1);
	}
	if (ft_initenv(envp))
	{
		perror("gigachell");
		return (1);
	}
	status = main_loop();
	rl_clear_history();
	ft_clearenv();
	// patch_readline_leaks();
	printf("found elf at -> %p\n", elf_base(&main));
	printf("libc elf at -> %p\n", find_elf_byname("libc"));
	printf("malloc address at -> %p\n", &malloc);
	printf("libtinfo elf at -> %p\n", find_elf_byname("libtinfo"));
	printf("libreadline elf at -> %p\n", find_elf_byname("libreadline"));
	breakpoint();
	return (status);
}
