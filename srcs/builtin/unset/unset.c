/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:29:54 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/12 11:37:32 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "redirect_fd.h"
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
