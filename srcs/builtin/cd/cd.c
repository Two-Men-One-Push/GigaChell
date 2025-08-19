/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:25:26 by ebini             #+#    #+#             */
/*   Updated: 2025/08/20 00:09:20 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "env.h"
#include "libft.h"
#include "defs/redirect_fd.h"

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
	if (!new_pwd || ft_setenv("PWD", new_pwd))
	{
		perror("gigachell: cd");
		free(new_pwd);
		return (1);
	}
	free(new_pwd);
	return (0);
}
