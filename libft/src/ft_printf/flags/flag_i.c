/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:16:58 by ebini             #+#    #+#             */
/*   Updated: 2025/01/15 19:02:29 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdarg.h>
#include <unistd.h>

static int	handle_n(int fd, int n, char *c, ssize_t *write_len)
{
	if (n < 0)
	{
		*write_len = write(fd, "-", 1);
		*c = '0' - n % 10;
		return (-(n / 10));
	}
	else
	{
		*write_len = 0;
		*c = '0' + n % 10;
		return (n / 10);
	}
}

size_t	print_int(int fd, int n)
{
	char	c;
	ssize_t	printed_len;
	ssize_t	write_size;

	n = handle_n(fd, n, &c, &printed_len);
	printed_len = printed_len == 1;
	if (n)
		printed_len += print_int(fd, n);
	write_size = write(fd, &c, 1) > 0;
	return (printed_len + write_size);
}

size_t	print_i(int fd, va_list value)
{
	return (print_int(fd, va_arg(value, int)));
}
