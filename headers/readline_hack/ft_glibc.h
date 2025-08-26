/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glibc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 21:35:17 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/26 06:49:17 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLIBC_H
# define FT_GLIBC_H

# include <stdlib.h>

typedef struct s_malloc_chunk
{
	size_t				prev_size;
	size_t				size;
	struct malloc_chunk	*fd;
	struct malloc_chunk	*bk;
}	t_malloc_chunk;

typedef t_malloc_chunk	*t_mchunkptr;

typedef struct s_malloc_state
{
	int					mutex;
	int					flags;
	t_mchunkptr			fastbinsy[10];
	t_mchunkptr			top;
	t_mchunkptr			last_remainder;
	t_mchunkptr			bins[254 * 2];
	unsigned int		binmap[4];
	struct malloc_state	*next;
	struct malloc_state	*next_free;
	size_t				system_mem;
	size_t				max_system_mem;
}	t_malloc_state;

typedef struct s_heap_info
{
	t_malloc_state		*ar_ptr;
	struct s_heap_info	*prev;
	size_t				size;
	size_t				mprotect_size;
}	t_heap_info;

#endif