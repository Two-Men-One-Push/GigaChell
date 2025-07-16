/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:21:04 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/17 00:55:05 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <readline/readline.h>
#include "signal_handling.h"

void	handling_prompt_signal(void)
{
	struct sigaction	sigint_sa;
	struct sigaction	sigquit_sa;

	sigint_sa.sa_flags = 0;
	sigint_sa.sa_handler = &sigint_handler;
	sigemptyset(&sigint_sa.sa_mask);
	sigaction(SIGINT, &sigint_sa, NULL);
	sigquit_sa.sa_flags = 0;
	sigquit_sa.sa_handler = SIG_IGN;
	sigemptyset(&sigquit_sa.sa_mask);
	sigaction(SIGQUIT, &sigquit_sa, NULL);
}

void	handling_execution_signal(void)
{
	struct sigaction	sigint_sa;
	struct sigaction	sigquit_sa;

	sigint_sa.sa_flags = 0;
	sigint_sa.sa_handler = SIG_IGN;
	sigemptyset(&sigint_sa.sa_mask);
	sigaction(SIGINT, &sigint_sa, NULL);
	sigquit_sa.sa_flags = 0;
	sigquit_sa.sa_handler = SIG_IGN;
	sigemptyset(&sigquit_sa.sa_mask);
	sigaction(SIGQUIT, &sigquit_sa, NULL);
}

void	handling_child_signal(void)
{
	struct sigaction	sigint_sa;
	struct sigaction	sigquit_sa;

	sigint_sa.sa_flags = 0;
	sigint_sa.sa_handler = SIG_DFL;
	sigemptyset(&sigint_sa.sa_mask);
	sigaction(SIGINT, &sigint_sa, NULL);
	sigquit_sa.sa_flags = 0;
	sigquit_sa.sa_handler = SIG_DFL;
	sigemptyset(&sigquit_sa.sa_mask);
	sigaction(SIGQUIT, &sigquit_sa, NULL);
}
