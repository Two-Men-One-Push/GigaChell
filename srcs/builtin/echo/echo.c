/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:36:18 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/22 21:09:32 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirect_fd.h"
#include <unistd.h>

int	valid_options(char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		++i;
	}
	if (i == 1)
		return (0);
	return (1);
}

int	ft_echo(int argc, char **argv, t_redirect_fd *redirect)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (i < argc && valid_options(argv[i]))
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
