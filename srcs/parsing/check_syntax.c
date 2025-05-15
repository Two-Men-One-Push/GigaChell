/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:42:09 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/14 20:48:31 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	check_syntax(char *line)
{
	t_size	index;
	int		scope;

	index = 0;
	scope = 0;
	while (line[index])
	{
		if (line[index] == '(')
			++scope;
		if (line[index] == ')')
			--scope;
		if (scope < 0)
			return (syntax_error((t_stref){&line[index], 1}));
		++index;
	}
	return (0);
}
