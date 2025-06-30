/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:54:35 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 15:32:30 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "redirect_fd.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

bool	are_same_path(const char *path1, const char *path2)
{
	struct stat	st1;
	struct stat	st2;

	if (stat(path1, &st1) != 0 || stat(path2, &st2) != 0)
		return (false);
	return ((st1.st_ino == st2.st_ino) && (st1.st_dev == st2.st_dev));
}

static int	secure_pwd(t_redirect_fd *redirect)
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

int	ft_pwd(int argc, char **argv, t_redirect_fd *redirect)
{
	(void)argc;
	(void)argv;
	if (secure_pwd(redirect))
		return (1);
	ft_dprintf(redirect->out, "%s\n", ft_getenv("PWD"));
	return (0);
}
