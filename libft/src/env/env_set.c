/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:16:37 by ebini             #+#    #+#             */
/*   Updated: 2025/04/30 21:58:49 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "env.h"

#include <stdio.h>

static int	replace_var(char **var, char *var_name, char *value)
{
	free(*var);
	*var = strjoinall(3, var_name, "=", value);
	if (!*var)
		return (1);
	return (0);
}

static int	set_var(char **var, char *var_name, char *value, size_t	name_len)
{
	const size_t	value_len = ft_strlen(value);

	if (ft_strlen(*var) < value_len + name_len + 1)
		return (replace_var(var, var_name, value));
	ft_strcpy(*var + name_len + 1, value);
	return (0);
}

int	push_var(t_env *env, char *var_name, char *value, size_t i)
{
	if (i == env->capacity - 1)
		increase_env_capacity(env);
	env->data[i] = strjoinall(3, var_name, "=", value);
	env->data[i + 1] = NULL;
	return (0);
}

int	env_set(t_env *env, char *var_name, char *value)
{
	const size_t	name_len = ft_strlen(var_name);
	char			**env_tab;
	char			**unsetted_var;
	size_t			i;

	env_tab = env->data;
	unsetted_var = NULL;
	i = 0;
	while (env_tab[i])
	{
		if (starts_by(env_tab[i], var_name))
		{
			if (env_tab[i][name_len] == '=')
				return (set_var(env_tab + i, var_name, value, name_len));
			if (!env_tab[i][name_len])
				return (replace_var(env_tab + i, var_name, value));
		}
		if (!ft_strchr(env_tab[i], '='))
			unsetted_var = env_tab + i;
		++i;
	}
	if (unsetted_var)
		return (replace_var(unsetted_var, var_name, value));
	return (push_var(env, var_name, value, i));
}
