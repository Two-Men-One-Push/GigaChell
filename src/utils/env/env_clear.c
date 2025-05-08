/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:02:17 by ebini             #+#    #+#             */
/*   Updated: 2025/05/08 17:12:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"

void	env_clear(t_env *env)
{
	size_t	i;

	i = -1;
	while (env->data[++i])
		free(env->data[i]);
	free(env->data);
}
