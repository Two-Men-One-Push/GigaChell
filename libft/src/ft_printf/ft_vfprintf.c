/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:01:46 by ebini             #+#    #+#             */
/*   Updated: 2025/01/19 18:54:07 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "./ft_vfprintf_utils.h"

size_t	print_text(int fd, const char **format)
{
	size_t	offset;
	ssize_t	writed_len;

	offset = len_flag(*format);
	writed_len = write(fd, *format, offset);
	*format += offset;
	if (writed_len < 0)
		return (0);
	return (writed_len);
}

size_t	print_flag(int fd, const char **format, va_list args)
{
	size_t	flag_value;

	++(*format);
	flag_value = handle_flag(fd, *format, args);
	++(*format);
	return (flag_value);
}

int	ft_vfprintf(int fd, const char *format, va_list args)
{
	int		text_len;
	int		printed_len;
	int		flag_value;

	if (!format)
		return (-1);
	printed_len = 0;
	while (*format)
	{
		text_len = print_text(fd, &format);
		if (text_len < 0)
			printed_len += text_len;
		printed_len += text_len;
		if (*format)
		{
			flag_value = print_flag(fd, &format, args);
			printed_len += flag_value;
		}
	}
	return (printed_len);
}
