/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/14 20:01:54 by ethebaul         ###   ########.fr       */
=======
/*   Updated: 2025/05/15 20:10:48 by ethebaul         ###   ########.fr       */
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "env.h"
#include "gigachell.h"
<<<<<<< HEAD
#include <stdio.h>
#include <readline/readline.h>
=======
#include "defs/hd_node.h"
#include "readline/readline.h"
#include "libft.h"
#include "builtin.h"
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c

int	main(int ac, char **av, char **envp)
{
	t_hd_node	*heredoc_list;
	char		*line;

	(void)av;
<<<<<<< HEAD
	(void)envp;
	while (!check_syntax(readline(NULL)))
		;
	return (0);
=======
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
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c
}
