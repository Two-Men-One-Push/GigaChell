/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:00:32 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/20 04:47:04 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "env.h"
#include "redirect_fd.h"
#include "utils.h"

int	ft_env(int argc, char **argv, t_redirect_fd	*redirect)
{
	char	**env;

	(void)argc;
	(void)argv;
	env = ft_getenvp();
	if (!env)
	{
		perror("gigachell: env");
		return (1);
	}
	dprint_tab(redirect->out, env);
	free(env);
	return (0);
}
