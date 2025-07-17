/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 10:13:14 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/17 02:16:23 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>

int	g_sigint;

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
	g_sigint = 1;
}

int	signal_event_hook(void)
{
	if (g_sigint)
	{
		rl_done = 1;
		return (0);
	}
	return (0);
}
