/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 10:13:14 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/12 10:13:53 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>

void	sigint_handler(int code)
{
	(void)code;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sigint_ignore(int code)
{
	(void)code;
	printf("\n");
}

void	sigquit_handler(int code)
{
	(void)code;
	printf("Quit\n");
}

void	sigquit_ignore(int code)
{
	(void)code;
}
