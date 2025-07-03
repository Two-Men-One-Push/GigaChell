/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:02:52 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 19:41:32 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs/redirect_fd.h"
#include "builtins.h"
#include "env.h"
#include "libft.h"
#include "utils.h"

int	start_builtin(char **argv, t_redirect_fd *redirect, int *builtin_status)
{
	const int		argc = ft_arrlen((void **)argv);
	t_redirect_fd	used_redirect;

	if (redirect->in < 0)
		used_redirect.in = 0;
	if (redirect->out < 0)
		used_redirect.out = 1;
	if (!ft_strcmp(*argv, "echo"))
		*builtin_status = ft_echo(argc, argv, &used_redirect);
	else if (!ft_strcmp(*argv, "cd"))
		*builtin_status = ft_cd(argc, argv, &used_redirect);
	else if (!ft_strcmp(*argv, "pwd"))
		*builtin_status = ft_pwd(argc, argv, &used_redirect);
	else if (!ft_strcmp(*argv, "export"))
		*builtin_status = ft_export(argc, argv, &used_redirect);
	else if (!ft_strcmp(*argv, "unset"))
		*builtin_status = ft_unset(argc, argv, &used_redirect);
	else if (!ft_strcmp(*argv, "env"))
		*builtin_status = ft_env(argc, argv, &used_redirect);
	else if (!ft_strcmp(*argv, "exit"))
		*builtin_status = ft_exit(argc, argv, &used_redirect);
	else
		return (1);
	return (0);
}
