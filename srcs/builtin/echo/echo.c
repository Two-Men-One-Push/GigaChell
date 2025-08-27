/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:36:18 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/27 21:03:32 by ebini            ###   ########lyon.fr   */
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
		ft_dprintf(redirect->out, "%s", argv[i]);
		if (i < argc -1)
			ft_dprintf(redirect->out, " ");
		++i;
	}
	if (newline)
		ft_dprintf(redirect->out, "\n");
	return (0);
}
