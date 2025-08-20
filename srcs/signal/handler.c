/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 10:13:14 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/20 04:14:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#include "global.h"

int	g_signum = 0;

void	sigint_handler(int code)
{
	(void)code;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sigquit_handler(int code)
{
	(void)code;
	printf("Quit\n");
}

void	hd_sigint_handler(int code)
{
	(void)code;
	g_signum = SIGINT;
}

int	signal_event_hook(void)
{
	if (g_signum == SIGINT)
	{
		rl_done = 1;
		return (0);
	}
	return (0);
}
