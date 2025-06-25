/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:47 by ebini             #+#    #+#             */
/*   Updated: 2025/06/25 18:49:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "print_buffer.h"

size_t	len_flag(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	return (i);
}

size_t	print_base(t_pbuff *buffer, unsigned long long n, char *base,
	int base_len)
{
	char	c;
	size_t	(void)!writed_size;

	c = n % base_len;
	n /= base_len;
	if (n)
		(void)!writed_size = print_base(buffer, n, base, base_len);
	else
		(void)!writed_size = 0;
	if (pbuff_write(buffer, base + c, 1) >= 0)
		++writed_size;
	return (writed_size);
}
