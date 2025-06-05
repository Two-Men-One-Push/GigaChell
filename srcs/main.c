/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:00:29 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 19:03:03 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline/readline.h"
#include "readline/history.h"
#include "syntax.h"
#include <unistd.h>

int	main(void)
{
	t_string	string;
	char		*str;

	write(1, "\033]0;Gigachell 𓀐𓂸 \007", 25);
	while (1)
	{
		str = readline("Gigachell: ");
		if (syntaxer(ftstring(str, ftstrlen(str))) == 0)
		{
			
		}
	}
	return (0);
}
