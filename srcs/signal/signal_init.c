/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:21:04 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/12 10:44:48 by CyberOneFR       ###   ########.fr       */
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

	sigint_sa.sa_flags = SA_RESTART;
	sigint_sa.sa_handler = &sigint_handler;
	if (sigaction(SIGINT, &sigint_sa, NULL))
		return (1);
	sigquit_sa.sa_flags = SA_RESTART;
	sigquit_sa.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sigquit_sa, NULL))
		return (1);
	return (0);
}

int	handling_execution_signal(void)
{
	struct sigaction	sigint_sa;
	struct sigaction	sigquit_sa;

	sigint_sa.sa_flags = SA_RESTART;
	sigint_sa.sa_handler = &sigint_ignore;
	if (sigaction(SIGINT, &sigint_sa, NULL))
		return (1);
	sigquit_sa.sa_flags = SA_RESTART;
	sigquit_sa.sa_handler = &sigquit_handler;
	if (sigaction(SIGQUIT, &sigquit_sa, NULL))
		return (1);
	return (0);
}
