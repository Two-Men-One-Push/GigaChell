/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:54 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 19:05:15 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "redirect_fd.h"
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	ft_unset(int argc, char **argv, t_redirect_fd *redirect)
{
	int	i;

	i = 1;
	(void)redirect;
	if (argc < 2)
	{
		ft_dprintf(STDERR_FILENO, "unset: not enough arguments\n");
		return (1);
	}
	while (i < argc)
	{
		ft_unsetenv(argv[i]);
		++i;
	}
	return (0);
}
