/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 04:23:36 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 19:18:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstring.h"
#include <stddef.h>

int	skipto(t_string string, size_t *index, char c)
{
	while (*index < string.size)
	{
		if (string.ptr[*index] == c)
			return (0);
		++*index;
	}
	return (-1);
}
