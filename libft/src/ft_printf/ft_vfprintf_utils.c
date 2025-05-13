/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:53:47 by ebini             #+#    #+#             */
/*   Updated: 2025/01/19 18:53:54 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	len_flag(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	return (i);
}

size_t	print_base(int fd, unsigned long long n, char *base, int base_len)
{
	char	c;
	size_t	writed_size;

	c = n % base_len;
	n /= base_len;
	if (n)
		writed_size = print_base(fd, n, base, base_len);
	else
		writed_size = 0;
	if (write(fd, base + c, 1) >= 0)
		++writed_size;
	return (writed_size);
}
