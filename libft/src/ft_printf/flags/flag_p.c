/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:24:07 by ebini             #+#    #+#             */
/*   Updated: 2025/01/16 22:02:57 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vfprintf_utils.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

size_t	print_p(int fd, va_list value)
{
	uintptr_t	p;
	ssize_t		write_size;

	p = va_arg(value, uintptr_t);
	if (!p)
	{
		write_size = write(fd, "(nil)", 5);
		if (write_size < 0)
			return (0);
		return (write_size);
	}
	write_size = write(fd, "0x", 2);
	if (write_size < 0)
		write_size = 0;
	return (write_size + print_base(fd, p, "0123456789abcdef", 16));
}
