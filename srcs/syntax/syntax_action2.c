/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_action2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:41:19 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/22 11:15:58 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	syntax_quote(char **line, int *cmd)
{
	char	quote;

	quote = (*line)[0];
	++(*line);
	while ((*line)[0] != quote)
	{
		if ((*line)[0] == '\0')
			return (serror("unclosed quote"));
		++(*line);
	}
	*cmd = 1;
	return (0);
}

int	syntax_pipe(char **line, int *cmd, int *op)
{
	if (*cmd == 0)
		return (serror("missing command before \"|\""));
	*cmd = 0;
	*op = 2;
	++(*line);
	return (0);
}
