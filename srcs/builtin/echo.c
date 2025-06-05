/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:36:18 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 18:36:47 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "bmask.h"

int	ft_echo(int ac, char **av)
{
	t_bmask	opt;
	int		i;

	i = 0;
	opt.value = 0;
	while (i < ac)
	{
		if (opt.mask.b1)
		{
			write(1, av[i], ft_strlen(av[i]));
			write(1, " ", 1);
		}
		else if (av[i][0] == '-' && av[i][1] == 'n')
			opt.mask.b2 = 1;
		else
			opt.mask.b1 = 1;
		++i;
	}
	if (opt.mask.b2)
		write(1, "\n", 1);
	return (0);
}
