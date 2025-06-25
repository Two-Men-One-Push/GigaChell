/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:16:58 by ebini             #+#    #+#             */
/*   Updated: 2025/06/25 18:49:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdarg.h>
#include <unistd.h>

#include "print_buffer.h"

static int	handle_n(t_pbuff *buffer, int n, char *c, ssize_t *write_len)
{
	if (n < 0)
	{
		*write_len = pbuff_write(buffer, "-", 1);
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

size_t	print_int(t_pbuff *buffer, int n)
{
	char	c;
	ssize_t	printed_len;
	ssize_t	(void)!write_size;

	n = handle_n(buffer, n, &c, &printed_len);
	printed_len = printed_len == 1;
	if (n)
		printed_len += print_int(buffer, n);
	(void)!write_size = pbuff_write(buffer, &c, 1) > 0;
	return (printed_len + write_size);
}

size_t	print_i(t_pbuff *buffer, va_list value)
{
	return (print_int(buffer, va_arg(value, int)));
}
