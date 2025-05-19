/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:31:53 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 22:47:08 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "heredoc_list_utils.h"
#include "heredoc.h"
#include "identifier.h"
#include "utils.h"

bool	parse_heredoc(char *cmd, t_hd_node **heredoc_list)
{
	size_t		i;
	char		*limiter;
	int			fd;
	t_hd_node	*new_node;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '<' && cmd[i + 1] == '<')
		{
			i += 2;
			limiter = get_limiter(cmd, &i);
			if (!limiter)
				return (true);
			fd = create_here_doc(limiter);
			free(limiter);
			if (fd < 0)
				return (true);
			new_node = hd_new(fd);
			if (!new_node)
			{
				hd_clear(heredoc_list);
				return (true);
			}
			hd_add_front(heredoc_list, new_node);
		}
	}
	return (false);
}
