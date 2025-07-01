/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:00:32 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 18:13:02 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (1);
	dprint_tab(redirect->out, env);
	return (0);
}
