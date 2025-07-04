/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 20:27:52 by ebini             #+#    #+#             */
/*   Updated: 2025/07/04 16:11:05 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs/redirect_fd.h"
#include <unistd.h>

#include "utils.h"

#include <stdio.h>

int	apply_redirection(t_redirect_fd *redirect)
{
	if (redirect->in > -1)
	{
		if (dup2(redirect->in, STDIN_FILENO) < 0)
		{
			perror("dup2");
			secure_close(redirect->in);
			return (1);
		}
		secure_close(redirect->in);
		redirect->in = -1;
	}
	if (redirect->out > -1)
	{
		if (dup2(redirect->out, STDOUT_FILENO) < 0)
		{
			perror("dup2");
			secure_close(redirect->out);
			return (1);
		}
		secure_close(redirect->out);
		redirect->out = -1;
	}
	return (0);
}
