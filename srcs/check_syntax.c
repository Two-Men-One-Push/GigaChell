/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 03:04:20 by ebini             #+#    #+#             */
/*   Updated: 2025/05/19 09:36:04 by ethebaul         ###   ########.fr       */
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

int	syntax_action(char **line, int *cmd, int *op, int *depth)
{
	if (*line[0] == '(')
	{
		if (*cmd)
			return (serror("(", 1));
		++*depth;
		*op = 0;
	}
	else if (*line[0] == ')')
	{
		if (!*cmd)
			return (serror(")", 1));
		--*depth;
		*op = 1;
	}
	else if (*line[0] == '&' && *line[1] == '&')
	{
		if (!*cmd)
			return (serror("&&", 2));
		*op = 0;
		++*line;
	}
	else if (*line[0] == '|' && *line[1] == '|')
	{
		if (!*cmd)
			return (serror("||", 1));
		*op = 0;
		++*line;
	}
	else if ((*line[0] < 9 || *line[0] > 13) && *line[0] != ' ')
		*op = 1;
	return (0);
}

int	check_syntax(char *line)
{
	int		depth;
	int		cmd_op;

	cmd_op = 0;
	depth = 0;
	while (*line)
	{
		if (syntax_action(line, &cmd_op, &depth))
			return (-1);
		++line;
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

int	syntax_popen(char *line, &depth);

int	syntax_pclose();