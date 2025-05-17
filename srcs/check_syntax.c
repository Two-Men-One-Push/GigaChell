/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 03:04:20 by ebini             #+#    #+#             */
/*   Updated: 2025/05/17 09:26:29 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include "utils.h"
#include "identifier.h"
#include "error.h"

int	serror(char *str, int len)
{
	write(2, "Gigachell: syntax error near unexpected token `", 47);
	write(2, str, len);
	write(2, "'\n", 2);
	return (-1);
}

int	syntax_action(char *line, int *i, int *cmd_op, int *depth)
{
	if (line[*i] == '(')
	{
		++*depth;
		*cmd_op &= 1;
	}
	else if (line[*i] == ')')
	{
		if ((*cmd_op & 2) == 0)
			return (serror(")", 1));
		--*depth;
		*cmd_op |= 2;
	}
	else if (line[*i] == '&' && line[*i + 1] == '&')
	{
		if ((*cmd_op & 2) == 0)
			return (serror("&&", 2));
		*cmd_op = 0;
		++*i;
	}
	else if (line[*i] == '|' && line[*i + 1] == '|')
	{
		if ((*cmd_op & 2) == 0)
			return (serror("||", 1));
		*cmd_op = 1;
		++*i;
	}
	else if ((line[*i] < 9 || line[*i] > 13) && line[*i] != ' ')
		*cmd_op |= 2;
	return (0);
}

int	check_syntax(char *line)
{
	int		depth;
	int		cmd_op;
	int		i;

	i = 0;
	cmd_op = 0;
	depth = 0;
	while (line[i])
	{
		if (syntax_action(line, &i, &cmd_op, &depth))
			return (-1);
		++i;
	}
	if (cmd_op == 0)
		return (serror("&&", 2));
	else if (cmd_op == 1)
		return (serror("||", 2));
	else if (depth > 0)
		return (serror("(", 1));
	else if (depth < 0)
		return (serror(")", 1));
	return (0);
}
