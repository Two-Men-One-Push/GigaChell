/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:25:26 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 15:41:34 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "env.h"
#include "libft.h"
#include "builtins_utils.h"
#include "defs/redirect_fd.h"

static char	*get_curpath(const char *arg)
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
		ft_dperror(STDERR_FILENO, "gigachell: cd");
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

static int	end_cd(char *curpath)
{
	int	result;

	if (ft_setenv("OLDPWD", ft_getenv("PWD")))
	{
		ft_dperror(STDERR_FILENO, "gigachell: cd");
		result = 1;
	}
	if (ft_setenv("PWD", curpath))
	{
		ft_dperror(STDERR_FILENO, "gigachell: cd");
		result = 1;
	}
	free(curpath);
	return (result);
}

int	ft_cd(int argc, char **argv, t_redirect_fd *redirect)
{
	char	*arg;
	char	*curpath;
	int		result;

	(void)redirect;
	if (secure_pwd())
		return (1);
	if (argc < 2)
		arg = ft_getenv("HOME");
	else
		arg = argv[1];
	if (!*arg)
		return (0);
	curpath = get_curpath((char *)arg);
	if (!curpath)
		return (1);
	clean_path(curpath);
	result = chdir(curpath);
	if (result)
	{
		free(curpath);
		ft_dperror(STDERR_FILENO, "cd");
		return (1);
	}
	return (end_cd(curpath));
}
