/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:24:33 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/14 23:28:36 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_fd.h"
#include <unistd.h>
#include "env.h"
#include "builtins.h"

int	ft_export(int argc, char **argv, t_redirect_fd *redirect)
{
	int		i;
	int		j;

	i = 1;
	if (argc < 2)
		return (ft_env(argc, argv, redirect));
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '=')
			{
				argv[i][j] = '\0';
				ft_setenv(argv[i], &argv[i][j + 1]);
				break ;
			}
			++j;
		}
		++i;
	}
	return (0);
}
