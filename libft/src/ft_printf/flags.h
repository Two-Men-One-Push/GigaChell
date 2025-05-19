/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:43:39 by ebini             #+#    #+#             */
/*   Updated: 2025/01/15 19:01:04 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H
# include <stdarg.h>
# include <sys/types.h>

size_t	print_c(int fd, va_list value);
size_t	print_s(int fd, va_list value);
size_t	print_p(int fd, va_list value);
size_t	print_i(int fd, va_list value);
size_t	print_u(int fd, va_list value);
size_t	print_low_x(int fd, va_list value);
size_t	print_up_x(int fd, va_list value);

#endif