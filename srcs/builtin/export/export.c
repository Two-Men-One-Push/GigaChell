/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:24:33 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/17 03:16:21 by ethebaul         ###   ########.fr       */
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

	(void)redirect;
	i = 1;
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
