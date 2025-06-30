/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:36:18 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 15:22:54 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "redirect_fd.h"
#include <unistd.h>

int	ftecho(int ac, char **av, t_redirect_fd *redirect)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == 'n')
	{
		newline = 0;
		++i;
	}
	while (i < ac)
	{
		ft_dprintf(redirect->out, "%s", av[i]);
		++i;
	}
	if (newline)
		ft_dprintf(redirect->out, "\n");
	return (0);
}
