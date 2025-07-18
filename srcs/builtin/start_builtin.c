/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:02:52 by ebini             #+#    #+#             */
/*   Updated: 2025/07/12 10:59:04 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs/redirect_fd.h"
#include "builtins.h"
#include "libft.h"

int	start_builtin(char **argv, t_redirect_fd *redirect, int *builtin_status)
{
	const int		argc = ft_arrlen((void **)argv);
	t_redirect_fd	used_redirect;

	used_redirect = (t_redirect_fd){0, 1};
	if (redirect->in >= 0)
		used_redirect.in = redirect->in;
	if (redirect->out >= 0)
		used_redirect.out = redirect->out;
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
