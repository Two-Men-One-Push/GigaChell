/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:21:04 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/16 23:40:41 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <readline/readline.h>
#include "signal_handling.h"

int	handling_prompt_signal(void)
{
	struct sigaction	sigint_sa;
	struct sigaction	sigquit_sa;

	sigint_sa.sa_flags = 0;
	sigint_sa.sa_handler = &sigint_handler;
	if (sigemptyset(&sigint_sa.sa_mask))
		return (1);
	if (sigaction(SIGINT, &sigint_sa, NULL))
		return (1);
	sigquit_sa.sa_flags = 0;
	sigquit_sa.sa_handler = SIG_IGN;
	if (sigemptyset(&sigquit_sa.sa_mask))
		return (1);
	if (sigaction(SIGQUIT, &sigquit_sa, NULL))
		return (1);
	return (0);
}

int	handling_execution_signal(void)
{
	struct sigaction	sigint_sa;
	struct sigaction	sigquit_sa;

	sigint_sa.sa_flags = 0;
	sigint_sa.sa_handler = SIG_IGN;
	if (sigemptyset(&sigint_sa.sa_mask))
		return (1);
	if (sigaction(SIGINT, &sigint_sa, NULL))
		return (1);
	sigquit_sa.sa_flags = 0;
	sigquit_sa.sa_handler = SIG_IGN;
	if (sigemptyset(&sigquit_sa.sa_mask))
		return (1);
	if (sigaction(SIGQUIT, &sigquit_sa, NULL))
		return (1);
	return (0);
}

int	handling_child_signal(void)
{
	struct sigaction	sigint_sa;
	struct sigaction	sigquit_sa;

	sigint_sa.sa_flags = 0;
	sigint_sa.sa_handler = SIG_DFL;
	if (sigemptyset(&sigint_sa.sa_mask))
		return (1);
	if (sigaction(SIGINT, &sigint_sa, NULL))
		return (1);
	sigquit_sa.sa_flags = 0;
	sigquit_sa.sa_handler = SIG_DFL;
	if (sigemptyset(&sigquit_sa.sa_mask))
		return (1);
	if (sigaction(SIGQUIT, &sigquit_sa, NULL))
		return (1);
	return (0);
}
