/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 04:42:35 by ebini             #+#    #+#             */
/*   Updated: 2025/06/10 06:50:29 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*expand(char *cmd)
{
	char	*var;
	char	*result;
	int		j;
	int		i;

	i = 0;
	while (ft_isalnum(cmd[i]) || cmd[i] == '_')
		++i;
	var = malloc((i + 1) * sizeof(char));
	var[i] = 0;
	j = 0;
	while (j < i)
	{
		var[j] = cmd[j];
		++j;
	}
	printf("%s\n", var);
	result = ft_getenv(var);
	free(var);
	return (result);
}
