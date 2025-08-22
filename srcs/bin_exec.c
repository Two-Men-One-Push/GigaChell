/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 06:46:12 by ebini             #+#    #+#             */
/*   Updated: 2025/08/20 04:23:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "env.h"
#include "libft.h"

int	find_bin(char **folders, char *cmd, char **result)
{
	int		status;

	status = 0;
	while (*folders)
	{
		*result = strjoinall(3, *folders, "/", cmd);
		if (!*result)
		{
			perror("gigachell: strjoinall");
			return (1);
		}
		if (access(*result, F_OK))
			status = 127 - (status == 126);
		else if (access(*result, X_OK))
			status = 126;
		else
			return (0);
		free(*result);
		++folders;
	}
	if (status == 126)
		ft_dprintf(STDERR_FILENO, "gigachell: permission denied: %s\n", cmd);
	else if (status == 127)
		ft_dprintf(STDERR_FILENO, "gigachell: command not found: %s\n", cmd);
	return (status);
}

int	handle_path(char *cmd, char **result)
{
	int	status;

	status = 0;
	if (access(cmd, F_OK))
	{
		ft_dprintf(STDERR_FILENO, "gigachell: command not found: %s\n", cmd);
		status = 127;
	}
	else if (access(cmd, X_OK))
	{
		ft_dprintf(STDERR_FILENO, "gigachell: permission denied: %s\n", cmd);
		status = 126;
	}
	if (!status)
		*result = ft_strdup(cmd);
	return (status);
}

int	get_bin_path(char *cmd, char *path, char **result)
{
	char	**folders;
	int		status;

	status = 127;
	if (ft_strchr(cmd, '/'))
		return (handle_path(cmd, result));
	if (!*path)
	{
		ft_dprintf(2, "gigachell: command not found: %s\n", cmd);
		return (127);
	}
	folders = ft_split(path, ':');
	if (!folders)
	{
		perror("gigachell");
		return (1);
	}
	if (*folders && *cmd)
		status = find_bin(folders, cmd, result);
	else
		ft_dprintf(STDERR_FILENO, "gigachell: command not found: %s\n", cmd);
	free_split(folders);
	return (status);
}

int	bin_exec(char **cmd)
{
	char	**envp;
	char	*bin_path;
	int		path_result;

	path_result = get_bin_path(*cmd, ft_getenv("PATH"), &bin_path);
	if (path_result)
		return (path_result);
	envp = ft_getenvp();
	if (!envp)
	{
		free(bin_path);
		perror("gigachell");
		return (1);
	}
	execve(bin_path, cmd, envp);
	free(envp);
	free(bin_path);
	perror("gigachell");
	return (1);
}
