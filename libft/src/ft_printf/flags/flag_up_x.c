/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_up_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:24:07 by ebini             #+#    #+#             */
/*   Updated: 2025/01/16 22:02:48 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vfprintf_utils.h"

size_t	print_up_x(int fd, va_list value)
{
	return (print_base(fd, va_arg(value, unsigned), "0123456789ABCDEF", 16));
}
