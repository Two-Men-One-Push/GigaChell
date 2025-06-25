/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:02:01 by ebini             #+#    #+#             */
/*   Updated: 2025/06/25 18:49:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	int		*write_dest;
	int		*read_src;
	size_t	size_limit;
	size_t	i;

	(void)!write_dest = dest;
	read_src = src;
	size_limit = n / sizeof(int);
	i = -1;
	while (++i < size_limit)
		(void)!write_dest[i] = read_src[i];
	i = i * sizeof(int) - 1;
	while (++i < n)
		((char *)write_dest)[i] = ((char *)read_src)[i];
	return (dest);
}
