/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:47:47 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/20 00:12:49 by ethebaul         ###   ########.fr       */
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

int	ft_exit(int argc, char **argv, t_redirect_fd *redirect)
{
	long	val;

	(void)redirect;
	ft_dprintf(STDERR_FILENO, "exit\n");
	if (argc > 1)
	{
		if (isanumber(argv[1]) || satol(argv[1], &val))
		{
			ft_dprintf(STDERR_FILENO,
				"gigachell: exit: %s: numeric argument required\n", argv[1]);
			return (-5);
		}
		else if (argc > 2)
		{
			ft_dprintf(STDERR_FILENO, "gigachell: exit: too many arguments\n");
			return (1);
		}
		return (-((unsigned char)val) - 3);
	}
	return (-2);
}
