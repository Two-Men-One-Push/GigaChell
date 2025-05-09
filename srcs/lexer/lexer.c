/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:34:10 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/09 16:12:02 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int	lexer(char *line)
{
	char	**tokens;

	tokens = lexer_tokenize(line);
	lexer_apply(tokens);
	free_array(tokens);
	return (0);
}
