/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 20:01:54 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gigachell.h"
#include <stdio.h>
#include <readline/readline.h>

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	while (!check_syntax(readline(NULL)))
		;
	return (0);
}
