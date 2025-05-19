/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 03:04:20 by ebini             #+#    #+#             */
/*   Updated: 2025/05/19 11:02:46 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "syntax.h"

int	serror(char *str)
{
	ft_dprintf(STDERR_FILENO, "Gigachell: syntax error %s\n", str);
	return (2);
}

int	check_syntax(char *line)
{
	int		depth;
	int		cmd;
	int		op;

	cmd = 0;
	op = -1;
	depth = 0;
	while (*line)
	{
		if (syntax_action(&line, &cmd, &op, &depth))
			return (2);
		++line;
	}
	if (cmd == 1 && op == 0)
		return (serror("missing command after \"&&\""));
	else if (cmd == 1 && op == 1)
		return (serror("missing command after \"||\""));
	else if (depth > 0)
		return (serror("unclosed \"(\""));
	else if (depth < 0)
		return (serror("unexpected \")\""));
	return (0);
}
