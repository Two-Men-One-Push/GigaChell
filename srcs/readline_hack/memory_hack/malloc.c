/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 06:16:02 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/26 06:33:26 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_glibc.h"
#include "readline_hack.h"
#include <stddef.h>

void	*find_main_arena(void)
{
	const void		*ptr = malloc(0x100);
	t_malloc_chunk	*mchunk;
	t_segment		segments;

	segments.base = find_elf_byname("libc");
	segments.data = get_seg_data(segments.base);
	segments.data_end = segments.data + get_seg_data_size(segments.base);
	if (!segments.base || !segments.data || !segments.data_end || !ptr)
		return (NULL);
	mchunk = (t_malloc_chunk *)(ptr - (2 * sizeof(size_t)));
	free((void *)ptr);
	while (segments.data < segments.data_end)
	{
		if (*(void **)segments.data == (void *)mchunk)
			return ((void *)(segments.data - 0x10));
		++segments.data;
	}
	return (NULL);
}
