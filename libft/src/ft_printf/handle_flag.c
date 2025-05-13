/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:28 by ebini             #+#    #+#             */
/*   Updated: 2025/01/15 18:56:19 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./flags.h"

size_t	handle_flag(int fd, const char *format, va_list args)
{
	if (*format == 'c')
		return (print_c(fd, args));
	else if (*format == 's')
		return (print_s(fd, args));
	else if (*format == 'p')
		return (print_p(fd, args));
	else if (*format == 'd' || *format == 'i')
		return (print_i(fd, args));
	else if (*format == 'u')
		return (print_u(fd, args));
	else if (*format == 'x')
		return (print_low_x(fd, args));
	else if (*format == 'X')
		return (print_up_x(fd, args));
	else if (*format == '%')
		return (write(fd, format, 1) > 0);
	return (-1);
}
