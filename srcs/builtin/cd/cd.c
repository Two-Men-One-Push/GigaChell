/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:25:26 by ebini             #+#    #+#             */
/*   Updated: 2025/05/21 08:46:18 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "env.h"
#include "libft.h"
#include "builtins_utils.h"
#include "defs/std_fd.h"

static int	secure_pwd(t_std_fd *redirect)
{
	char	*cwd;
	char	*pwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_dperror(redirect->err, "gigachell: cd");
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
		ft_dperror(redirect->err, "gigachell: cd");
		return (-1);
	}
	free(cwd);
	return (0);
}

static char	*get_curpath(const char *arg, t_std_fd *redirect)
{
	char	*pwd;
	char	*curpath;

	if (*arg == '/')
		curpath = ft_strdup(arg);
	else
	{
		pwd = ft_getenv("PWD");
		curpath = strjoinall(3, pwd, "/", arg);
	}
	if (!curpath)
		ft_dperror(redirect->err, "gigachell: cd");
	return (curpath);
}

static void	clean_path(char *path)
{
	size_t	i;

	i = 1;
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == '/')
			remove_path_dot(path, i);
		else if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '/')
			remove_path_dot_dot(path, &i);
		else if (path[i] == '/' && path[i - 1] == '/')
			clean_path_slash(path, i);
		else
			++i;
	}
	handle_path_end(path, i);
}

static int	end_cd(char *curpath, t_std_fd *redirect)
{
	int	result;

	if (ft_setenv("OLDPWD", ft_getenv("PWD")))
	{
		ft_dperror(redirect->err, "gigachell: cd");
		result = 1;
	}
	if (ft_setenv("PWD", curpath))
	{
		ft_dperror(redirect->err, "gigachell: cd");
		result = 1;
	}
	free(curpath);
	return (result);
}

int	cd(int ac, char **av, t_std_fd *redirect)
{
	char	*arg;
	char	*curpath;
	int		result;

	if (secure_pwd(redirect))
		return (1);
	if (ac < 2)
		arg = ft_getenv("HOME");
	else
		arg = av[1];
	if (!*arg)
		return (0);
	curpath = get_curpath((char *)arg, redirect);
	if (!curpath)
		return (1);
	clean_path(curpath);
	result = chdir(curpath);
	if (result)
	{
		free(curpath);
		ft_dperror(redirect->err, "cd");
		return (1);
	}
	return (end_cd(curpath, redirect));
}
