/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:02:52 by ebini             #+#    #+#             */
/*   Updated: 2025/06/28 05:52:18 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs/redirect_fd.h"
#include "builtins.h"
#include "libft.h"

int	start_builtin(char **argv, t_redirect_fd *redirect, int *builtin_status)
{
	const int	ac = ft_arrlen((void **)argv);

	if (!ft_strcmp(*argv, "echo"))
		*builtin_status = 0;
	else if (!ft_strcmp(*argv, "cd"))
		*builtin_status = cd(ac, argv, redirect);
	else if (!ft_strcmp(*argv, "pwd"))
		*builtin_status = 0;
	else if (!ft_strcmp(*argv, "export"))
		*builtin_status = 0;
	else if (!ft_strcmp(*argv, "unset"))
		*builtin_status = 0;
	else if (!ft_strcmp(*argv, "env"))
		*builtin_status = 0;
	else if (!ft_strcmp(*argv, "exit"))
		*builtin_status = -2;
	else
		return (1);
	return (0);
}
