/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 07:30:20 by ebini             #+#    #+#             */
/*   Updated: 2025/06/23 07:31:13 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "defs/redirect_fd.h"

void	clear_redirect(t_redirect_fd *redirect)
{
	if (redirect->in > -1)
		secure_close(redirect->in);
	if (redirect->out > -1)
		secure_close(redirect->out);
}
