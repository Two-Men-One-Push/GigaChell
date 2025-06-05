/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 05:31:08 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 19:18:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "print.h"

int	smalloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return (swrite(2, "Error malloc()\n", 16, -1));
	return (0);
}
