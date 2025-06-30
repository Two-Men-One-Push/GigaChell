/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:47:47 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 03:04:41 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "redirect_fd.h"

static int	isanumber(char *str)
{
	while (*str == ' ' || *str == '	')
		++str;
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		++str;
	}
	return (0);
}

static int	satol(char *str, long *val)
{
	long	sign;
	int		overflow;

	*val = 0;
	sign = 1;
	overflow = 0;
	while (*str == ' ' || *str == '	')
		++str;
	if (*str == '+' || *str == '-')
		sign = 44 - *(str++);
	while (*str >= '0' && *str <= '9')
	{
		overflow = __builtin_smull_overflow(*val, 10, val);
		overflow = __builtin_saddl_overflow(*val, *str - '0', val);
		++str;
	}
	__builtin_smull_overflow(*val, sign, val);
	return (overflow);
}

int	ftexit(int argc, char **argv, t_redirect_fd *redirect)
{
	long	val;

	(void)redirect;
	if (argc > 1)
	{
		if (isanumber(argv[1]) || satol(argv[1], &val))
		{
			ft_dprintf(STDERR_FILENO, \
				"exit: %s: numeric argument required\n", argv[1]);
			return (2);
		}
		else if (argc > 2)
		{
			ft_dprintf(STDERR_FILENO, "exit: too many arguments\n");
			return (-2);
		}
		return ((unsigned char)val);
	}
	return (-1);
}
