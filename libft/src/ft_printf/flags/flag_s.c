/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:44:58 by ebini             #+#    #+#             */
/*   Updated: 2025/01/16 22:02:53 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_vfprintf_utils.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

size_t	print_s(int fd, va_list value)
{
	char	*s;
	ssize_t	write_size;

	s = va_arg(value, char *);
	if (!s)
	{
		write_size = write(fd, "(null)", 6);
		if (write_size < 0)
			return (0);
		return (write_size);
	}
	write_size = write(fd, s, ft_strlen(s));
	if (write_size < 0)
		return (0);
	return (write_size);
}
