/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:21:04 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/20 03:51:49 by ebini            ###   ########lyon.fr   */
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

	rl_event_hook = NULL;
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

	rl_signal_event_hook = NULL;
	sigint_sa.sa_flags = 0;
	sigint_sa.sa_handler = SIG_DFL;
	sigemptyset(&sigint_sa.sa_mask);
	sigaction(SIGINT, &sigint_sa, NULL);
	sigquit_sa.sa_flags = 0;
	sigquit_sa.sa_handler = SIG_DFL;
	sigemptyset(&sigquit_sa.sa_mask);
	sigaction(SIGQUIT, &sigquit_sa, NULL);
}

void	handling_heredoc_signal(void)
{
	struct sigaction	sig_sa;

	sig_sa.sa_handler = hd_sigint_handler;
	sig_sa.sa_flags = 0;
	sigemptyset(&sig_sa.sa_mask);
	rl_event_hook = signal_event_hook;
	sigaction(SIGINT, &sig_sa, NULL);
}
