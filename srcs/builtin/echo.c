/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:36:18 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/27 19:03:31 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	echo(int ac, char **av)
{
	int	opt;
	int	i;
	int	j;

	i = 0;
	opt = 0;
	while (++i < ac)
	{
		j = 1;
		while (av[i][0] == '-' && av[i][j] == 'n')
			j++;
		if (av[i][j] != '\0')
			break ;
		opt = 1;
	}
	while (i < ac)
	{
		write(1, av[i], ft_strlen(av[i]));
		++i;
		if (i != ac)
			write(1, " ", 1);
	}
	if (!opt)
		write(1, "\n", 1);
	return (0);
}
