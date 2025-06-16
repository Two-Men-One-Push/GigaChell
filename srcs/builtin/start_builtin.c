/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:02:52 by ebini             #+#    #+#             */
/*   Updated: 2025/06/09 15:16:44 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs/redirect_fd.h"
#include "builtins.h"
#include "libft.h"

int	start_builtin(char **cmd, t_redirect_fd *redirect)
{
	const int	ac = ft_arrlen(cmd);

	if (!ft_strcmp(*cmd, "echo"))
		return (0);
	else if (!ft_strcmp(*cmd, "cd"))
		return (cd(ac, cmd, redirect));
	else if (!ft_strcmp(*cmd, "pwd"))
		return (0);
	else if (!ft_strcmp(*cmd, "export"))
		return (0);
	else if (!ft_strcmp(*cmd, "unset"))
		return (0);
	else if (!ft_strcmp(*cmd, "env"))
		return (0);
	else if (!ft_strcmp(*cmd, "exit"))
		return (0);
	return (-1);
}
