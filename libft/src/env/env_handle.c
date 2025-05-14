/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:12:48 by ebini             #+#    #+#             */
/*   Updated: 2025/04/30 23:57:54 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "env.h"

static void	*switch_action(int action, va_list args, t_env *env)
{
	if (action == ENV_INIT)
		return ((void *)(unsigned long)env_init(env, va_arg(args, char **)));
	else if (action == ENV_SET)
		return ((void *)(unsigned long)env_set(env,
			va_arg(args, char *), va_arg(args, char *)));
	else if (action == ENV_GET)
		return (env_get(env, va_arg(args, char *)));
	else if (action == ENV_UNSET)
		env_unset(env, va_arg(args, char *));
	else if (action == ENV_TO_ENVP)
		return (env_to_envp(env));
	else if (action == ENV_CLEAR)
		env_clear(env);
	return (NULL);
}

void	*env_handle(int action, ...)
{
	static t_env	env;
	va_list			args;
	void			*result;

	va_start(args, action);
	result = switch_action(action, args, &env);
	va_end(args);
	return (result);
}
