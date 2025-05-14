/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:25:13 by ebini             #+#    #+#             */
/*   Updated: 2025/04/30 21:21:31 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

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
