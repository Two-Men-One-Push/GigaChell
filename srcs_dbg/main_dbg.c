/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dbg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/05/15 20:13:11 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "gigachell.h"
#include "utils.h"
#include "heredoc_list_utils.h"
#include "heredoc.h"
#include "libft.h"
#include "env.h"
#include "builtins.h"

#ifndef PATH_MAX
# define PATH_MAX 4096
#endif

int	main(int ac, char **av, char **envp)
{
	char	cwd[PATH_MAX];

	printf("%s\n", getcwd(cwd, PATH_MAX));
	ft_initenv(envp);
	ft_setenv("PWD", "fnsjionpfequh");
	cd(ac, av);
	printf("%s\n", getcwd(cwd, PATH_MAX));
	printf("%s\n", ft_getenv("PWD"));
	ft_clearenv();
	return (0);
}
