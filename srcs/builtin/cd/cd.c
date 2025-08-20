/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:25:26 by ebini             #+#    #+#             */
/*   Updated: 2025/08/20 04:08:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "env.h"
#include "libft.h"
#include "defs/redirect_fd.h"

int	update_env(char *new_pwd)
{
	int result;

	result = 0;
	if (ft_setenv("OLDPWD", ft_getenv("PWD")))
	{
		ft_dprintf(STDERR_FILENO,
			"warning: couldn't update 'OLDPWD' environment variable\n");
		result = 1;
	}
	if (ft_setenv("PWD", new_pwd))
	{
		ft_dprintf(STDERR_FILENO,
			"warning: couldn't update 'PWD' environment variable\n");
		result = 1;
	}
	return (result);
}

int	ft_cd(int argc, char **argv, t_redirect_fd *redirect)
{
	int		result;
	char	*arg;
	char	*new_pwd;

	(void)redirect;
	if (argc < 2)
		arg = ft_getenv("HOME");
	else
		arg = argv[1];
	result = chdir(arg);
	if (result)
	{
		perror("gigachell: cd");
		return (1);
	}
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd || update_env(new_pwd))
	{
		perror("gigachell: cd");
		free(new_pwd);
		return (1);
	}
	free(new_pwd);
	return (0);
}
