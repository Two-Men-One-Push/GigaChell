/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:31:53 by ebini             #+#    #+#             */
/*   Updated: 2025/07/12 11:37:15 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "heredoc_list_utils.h"
#include "heredoc.h"
#include "utils.h"

#include <stdio.h>

static int	process_heredoc(char *cmd, size_t *i, t_hd_node **heredoc_list)
{
	char		*limiter;
	int			fd;
	t_hd_node	*new_node;
	bool		expand;

	limiter = get_limiter(cmd, i, &expand);
	if (!limiter)
		return (1);
	fd = create_here_doc(limiter, expand);
	free(limiter);
	if (fd < 0)
		return (1);
	new_node = hd_new(fd);
	if (!new_node)
		return (1);
	hd_add_front(heredoc_list, new_node);
	return (0);
}

int	parse_heredoc(char *cmd, t_hd_node **heredoc_list)
{
	size_t		i;

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
			if (process_heredoc(cmd, &i, heredoc_list))
			{
				hd_clear(heredoc_list);
				return (1);
			}
		}
		else
			++i;
	}
	return (0);
}
