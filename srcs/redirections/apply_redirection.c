/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 20:27:52 by ebini             #+#    #+#             */
/*   Updated: 2025/06/25 18:17:01 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs/redirect_fd.h"
#include <unistd.h>

#include "utils.h"

int	apply_redirection(t_redirect_fd *redirect)
{
	if (redirect->in > -1)
	{
		if (dup2(STDIN_FILENO, redirect->in))
			return (1);
	}
	if (redirect->out > -1)
	{
		if (dup2(STDOUT_FILENO, redirect->out))
		{
			secure_close(STDIN_FILENO);
			return (1);
		}
	}
	return (0);
}
