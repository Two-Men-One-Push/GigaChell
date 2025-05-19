/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:34:32 by ebini             #+#    #+#             */
/*   Updated: 2025/01/16 22:02:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../ft_vfprintf_utils.h"

size_t	print_unsigned(int fd, unsigned int n)
{
	char	c;
	size_t	child_len;

	c = '0' + n % 10;
	n /= 10;
	if (n)
		child_len = print_unsigned(fd, n);
	else
		child_len = 0;
	child_len += write(fd, &c, 1) > 0;
	return (child_len);
}

size_t	print_u(int fd, va_list value)
{
	return (print_unsigned(fd, va_arg(value, unsigned)));
}
