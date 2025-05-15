/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/05/15 20:10:48 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "env.h"
#include "gigachell.h"
#include "defs/hd_node.h"
#include "readline/readline.h"
#include "libft.h"
#include "builtin.h"

int	main(int ac, char **av, char **envp)
{
	t_hd_node	*heredoc_list;
	char		*line;

	(void)av;
	(void)ac;
	heredoc_list = NULL;
	if (ft_initenv(envp))
	{
		perror("minishell: ft_initenv");
		return (1);
	}
	while (1)
	{
		line = readline(NULL);
		if (check_syntax(line))
			continue ;
		//parse and exec
	}
	ft_clearenv();
	return (1);
}
