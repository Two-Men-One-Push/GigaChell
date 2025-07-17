/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:00:32 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/17 03:47:22 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "redirect_fd.h"
#include "utils.h"
#include <stdlib.h>

int	ft_env(int argc, char **argv, t_redirect_fd	*redirect)
{
	char	**env;

	(void)argc;
	(void)argv;
	env = ft_getenvp();
	if (!env)
		return (1);
	dprint_tab(redirect->out, env);
	free(env);
	return (0);
}
