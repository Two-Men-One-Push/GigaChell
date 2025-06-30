/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:25:13 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 16:58:50 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

char	*env_get(t_env *env, char *var_name)
{
	const size_t	name_len = env_var_len(var_name);
	char			**env_tab;

	env_tab = env->data;
	while (*env_tab)
	{
		if (!ft_strncmp(var_name, *env_tab, name_len)
			&& (*env_tab)[name_len] == '=')
			return (*env_tab + name_len + 1);
		++env_tab;
	}
	return ("");
}
