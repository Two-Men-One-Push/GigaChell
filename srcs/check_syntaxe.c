/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 03:04:20 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 04:25:43 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "utils.h"
#include "identifier.h"
#include "error.h"

// /**
//  * @return if there was a word in the string befor the next logical operator
//  */
// static int	skip_to_operator(char *cmd, size_t *i)
// {
// 	while (cmd[*i])
// 	{
// 		if (cmd[*i] == '\'')
// 			skip_squote(cmd, i);
// 		else if (cmd[*i] == '"')
// 			skip_dquote(cmd, i);
// 		else if (cmd[*i] == '(')
// 			skip_paranthesis(cmd, i);
// 		else if ((cmd[*i] == '&' && cmd[*i + 1] == '&') || (cmd[*i] == '|'
// 				&& cmd[*i + 1] == '|'))
// 			return ;
// 		else
// 			++*i;
// 	}
// }

// int	handle_logical_operator(int *i, bool *is_word)
// {
// 	if (!is_word)
// 		return (int_error("Syntaxe Error : Missing word before operator"));
// 	*i += 2;
// 	return (false);
// }

// int	switch_char(char *cmd, int *i, bool *is_word)
// {
// 	if (is_space(cmd[*i]))
// 			return 0;
// 	if (cmd[*i] == '"')
// 	{
// 		if (skip_dquote(cmd, &i))
// 			return (int_error("Syntaxe Error : Unclosed double quote."));
// 	}
// 	else if (cmd[*i] == '\'')
// 	{
// 		if (skip_squote(cmd, &i))
// 			return (int_error("Syntaxe Error : Unclosed single quote."));
// 	}
// 	else if ()
// 		return (handle_logical_operator(i, is_word));
// 	return (false);
// }

// bool	search_word(char *cmd, size_t *i)
// {
// 	while (cmd[*i])
// 	{
// 		if (is_space(cmd[*i]))
// 			continue;
// 		if ()
// 		++*i;
// 	}
// }

int	check_syntaxe(char *cmd)
{
	// size_t	i;
	// bool	is_word;
	// size_t	depth;

	// is_word = false;
	// depth = 0;
	// i = 1;
	// while (cmd[++i])
	// 	if (switch_char(cmd, &i))
	// 		return (true);
	// return (false);
	return (false);
}
