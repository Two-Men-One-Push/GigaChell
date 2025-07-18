/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:36:18 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/12 11:37:43 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirect_fd.h"
#include <unistd.h>

int	ft_echo(int argc, char **argv, t_redirect_fd *redirect)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == 'n')
	{
		newline = 0;
		++i;
	}
	while (i < argc)
	{
		if (i != 1 + !newline)
			ft_dprintf(redirect->out, " %s", argv[i]);
		else
			ft_dprintf(redirect->out, "%s", argv[i]);
		++i;
	}
	if (newline)
		ft_dprintf(redirect->out, "\n");
	return (0);
}
