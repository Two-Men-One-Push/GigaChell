/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:06:56 by ebini             #+#    #+#             */
/*   Updated: 2025/05/15 20:12:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

#include <stdio.h>

int	ft_setenv(char *var_name, char *value)
{
	return ((int)(unsigned long)env_handle(ENV_SET, var_name, value));
}
