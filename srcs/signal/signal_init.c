/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:21:04 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/11 22:20:44 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
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

int	handling_prompt_signal(void)
{
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

int	handling_execution_signal(void)
{
	signal(SIGINT, &sigint_ignore);
	signal(SIGQUIT, &sigquit_handler);
	return (0);
}
