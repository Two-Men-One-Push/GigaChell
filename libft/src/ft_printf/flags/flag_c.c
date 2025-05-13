/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:21:47 by ebini             #+#    #+#             */
/*   Updated: 2025/01/15 18:59:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

size_t	print_c(int fd, va_list value)
{
	char	c;
	int		write_size;

	c = va_arg(value, int);
	write_size = write(fd, &c, 1);
	if (write_size < 0)
		return (0);
	return (write_size);
}
