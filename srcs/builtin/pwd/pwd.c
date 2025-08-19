/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:54:35 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/19 16:21:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "env.h"
#include "libft.h"
#include "redirect_fd.h"

int	ft_pwd(int argc, char **argv, t_redirect_fd *redirect)
{
	char	*pwd;

	(void)argc;
	(void)argv;
	(void)redirect;
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("minishell: pwd");
		return (1);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
