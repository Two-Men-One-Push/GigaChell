/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dbg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 22:45:18 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "gigachell.h"
#include "utils.h"
#include "heredoc_list_utils.h"
#include "heredoc.h"
#include "libft.h"

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	// size_t		i = 0;
	// char		*limiter = 0;
	t_hd_node	*heredoc_list;
	t_hd_node	*current_node;

	heredoc_list = NULL;
	if (ac > 1)
	{
		if (parse_heredoc(av[1], &heredoc_list))
			return (1);
		current_node = heredoc_list;
		while (current_node)
		{
			printf("%d\n", current_node->fd);
			current_node = current_node->next;
		}
		hd_clear(&heredoc_list);
	}
	return (0);
}
