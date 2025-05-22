/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:29:37 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/22 11:13:46 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	syntax_action(char **line, int *cmd, int *op, int *depth)
{
	if (((*line)[0] == '\"' || (*line)[0] == '\''))
		return (syntax_quote(line, cmd));
	else if ((*line)[0] == '(')
		return (syntax_popen(cmd, depth));
	else if ((*line)[0] == ')')
		return (syntax_pclose(cmd, depth));
	else if ((*line)[0] == '&' && (*line)[1] == '&')
		return (syntax_and(line, cmd, op));
	else if ((*line)[0] == '|' && (*line)[1] == '|')
		return (syntax_or(line, cmd, op));
	else if ((*line)[0] == '|')
		return (syntax_pipe(line, cmd, op));
	else if (!((*line)[0] == '\t' || (*line)[0] == ' '))
		*cmd = 1;
	return (0);
}

int	syntax_popen(int *cmd, int *depth)
{
	if (*cmd == 1)
		return (serror("unexpected \"(\""));
	++*depth;
	*cmd = 0;
	return (0);
}

int	syntax_pclose(int *cmd, int *depth)
{
	if (*cmd == 0)
		return (serror("unexpected \")\""));
	--*depth;
	*cmd = 1;
	return (0);
}

int	syntax_and(char **line, int *cmd, int *op)
{
	if (*cmd == 0)
		return (serror("missing command before \"&&\""));
	*cmd = 0;
	*op = 0;
	++(*line);
	return (0);
}

int	syntax_or(char **line, int *cmd, int *op)
{
	if (*cmd == 0)
		return (serror("missing command before \"||\""));
	*cmd = 0;
	*op = 1;
	++(*line);
	return (0);
}
