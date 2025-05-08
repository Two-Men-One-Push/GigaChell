/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:25:13 by ebini             #+#    #+#             */
/*   Updated: 2025/05/08 17:12:37 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>

char	*env_get(t_env *env, char *var_name)
{
	const size_t	name_len = ft_strlen(var_name);
	char			**env_tab;

	env_tab = env->data;
	while (*env_tab)
	{
		if (starts_by(*env_tab, var_name) && (*env_tab)[name_len] == '=')
			return (*env_tab + name_len + 1);
		++env_tab;
	}
	return ("");
}
