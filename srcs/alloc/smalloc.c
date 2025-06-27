/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 05:31:08 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/27 17:24:08 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	smalloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
	{
		write(STDERR_FILENO, "Error malloc\n", 14);
		return (1);
	}
	return (0);
}
