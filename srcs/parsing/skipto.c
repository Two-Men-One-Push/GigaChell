/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 04:23:36 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 03:20:07 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstring.h"
#include <stddef.h>

int	skipto(char *str, size_t *index, char c)
{
	while (str[*index])
	{
		++*index;
		if (str[*index] == c)
			return (0);
	}
	return (-1);
}
