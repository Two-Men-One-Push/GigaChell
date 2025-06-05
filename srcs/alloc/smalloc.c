/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 05:31:08 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/27 19:42:21 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tsize.h"
#include <stdlib.h>
#include "print.h"

int	smalloc(void **ptr, t_size size)
{
	*ptr = malloc(size);
	if (!*ptr)
		return (swrite(2, "Error malloc()\n", 16, -1));
	return (0);
}
