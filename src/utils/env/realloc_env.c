/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:36:59 by ebini             #+#    #+#             */
/*   Updated: 2025/05/08 17:12:26 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include <stdio.h>

static int	realloc_env(t_env *env, size_t new_capacity)
{
	char	**new_data;
	size_t	i;

	new_data = malloc(new_capacity * sizeof(char *));
	if (!new_data)
		return (1);
	i = 0;
	while (env->data[i])
	{
		new_data[i] = env->data[i];
		++i;
	}
	new_data[i] = NULL;
	free(env->data);
	env->data = new_data;
	return (0);
}

int	increase_env_capacity(t_env *env)
{
	return (realloc_env(env, env->capacity * 2));
}

int	decrease_env_capacity(t_env *env)
{
	return (realloc_env(env, env->capacity / 2));
}
