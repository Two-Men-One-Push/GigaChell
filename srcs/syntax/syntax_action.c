/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:29:37 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/20 13:14:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"
#include "identifier.h"

int	syntax_action(char **line, int *cmd, int *op, int *depth)
{
	if ((*line)[0] == '(')
	{
		if (syntax_popen(cmd, depth))
			return (2);
	}
	else if ((*line)[0] == ')')
	{
		if (syntax_pclose(cmd, depth))
			return (2);
	}
	else if ((*line)[0] == '&' && (*line)[1] == '&')
	{
		if (syntax_and(line, cmd, op))
			return (2);
	}
	else if ((*line)[0] == '|' && (*line)[1] == '|')
	{
		if (syntax_or(line, cmd, op))
			return (2);
	}
	else if (!is_space((*line)[0]))
		*cmd = 1;
	return (0);
}

int	syntax_popen(int *cmd, int *depth)
{
	if (*cmd)
		return (serror("unexpected \"(\""));
	++*depth;
	*cmd = 0;
	return (0);
}

int	syntax_pclose(int *cmd, int *depth)
{
	if (!*cmd)
		return (serror("unexpected \")\""));
	--*depth;
	*cmd = 1;
	return (0);
}

int	syntax_and(char **line, int *cmd, int *op)
{
	if (!*cmd)
		return (serror("missing command before \"&&\""));
	*cmd = 0;
	*op = 0;
	++*line;
	return (0);
}

int	syntax_or(char **line, int *cmd, int *op)
{
	if (!*cmd)
		return (serror("missing command before \"||\""));
	*cmd = 0;
	*op = 1;
	++*line;
	return (0);
}
