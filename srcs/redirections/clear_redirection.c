/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:26:19 by ebini             #+#    #+#             */
/*   Updated: 2025/06/23 09:27:57 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_redirect(t_redirect_fd *redirect)
{
	if (redirect->in > -1)
		secure_close(redirect->in);
	if (redirect->out > -1)
		secure_close(redirect->out);
}
