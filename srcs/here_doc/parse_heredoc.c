/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:31:53 by ebini             #+#    #+#             */
/*   Updated: 2025/07/17 02:55:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "heredoc_list_utils.h"
#include "heredoc.h"
#include "utils.h"


static int	process_heredoc(char *cmd, size_t *i, t_hd_node **heredoc_list)
{
	char		*limiter;
	int			fd;
	t_hd_node	*new_node;
	bool		expand;

	limiter = get_limiter(cmd, i, &expand);
	if (!limiter)
		return (-1);
	fd = create_here_doc(limiter, expand);
	free(limiter);
	if (fd < 0)
		return (fd);
	new_node = hd_new(fd);
	if (!new_node)
	{
		close(fd);
		return (-1);
	}
	hd_add_front(heredoc_list, new_node);
	return (0);
}

int	parse_heredoc(char *cmd, t_hd_node **heredoc_list)
{
	size_t	i;
	int		heredoc_result;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
			skip_squote(cmd, &i);
		else if (cmd[i] == '"')
			skip_dquote(cmd, &i);
		else if (cmd[i] == '<' && cmd[i + 1] == '<')
		{
			i += 2;
			heredoc_result = process_heredoc(cmd, &i, heredoc_list);
			if (heredoc_result)
			{
				hd_clear(heredoc_list);
				return (heredoc_result);
			}
		}
		else
			++i;
	}
	return (0);
}
