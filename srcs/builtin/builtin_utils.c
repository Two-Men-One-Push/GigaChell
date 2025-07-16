/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:40:35 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/16 20:52:42 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "builtins_utils.h"

static bool	are_same_path(const char *path1, const char *path2)
{
	struct stat	st1;
	struct stat	st2;

	if (stat(path1, &st1) != 0 || stat(path2, &st2) != 0)
		return (false);
	return ((st1.st_ino == st2.st_ino) && (st1.st_dev == st2.st_dev));
}

int	secure_pwd(void)
{
	char	*cwd;
	char	*pwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_dperror(STDERR_FILENO, "gigachell");
		return (-1);
	}
	pwd = ft_getenv("PWD");
	if (*pwd == '/' && are_same_path(cwd, pwd))
	{
		free(cwd);
		return (0);
	}
	if (ft_setenv("PWD", cwd))
	{
		free(cwd);
		ft_dperror(STDERR_FILENO, "gigachell");
		return (-1);
	}
	free(cwd);
	return (0);
}
