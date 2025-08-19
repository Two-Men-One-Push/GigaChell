/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:24:33 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/19 16:17:38 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_fd.h"
#include <unistd.h>
#include "env.h"
#include "builtins.h"
#include "libft.h"

void	export_var(int argi, char **argv)
{
	int		j;

	j = 0;
	while (argv[argi][j])
	{
		if (argv[argi][j] == '=')
		{
			if (j < 1)
				return ;
			argv[argi][j] = '\0';
			ft_setenv(argv[argi], &argv[argi][j + 1]);
			break ;
		}
		if (j == 0 && !is_env_var_start(argv[argi][j]))
		{
			write(2, "bash: export: `", 16);
			write(2, argv[argi], ft_strlen(argv[argi]));
			write(2, "': not a valid identifier\n", 27);
		}
		++j;
	}
}

int	ft_export(int argc, char **argv, t_redirect_fd *redirect)
{
	int		i;

	(void)redirect;
	i = 1;
	while (i < argc)
	{
		export_var(i, argv);
		++i;
	}
	return (0);
}
