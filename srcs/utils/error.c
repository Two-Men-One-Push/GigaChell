/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:57:56 by ebini             #+#    #+#             */
/*   Updated: 2025/07/12 11:36:30 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

int	int_error(char *message)
{
	write(STDERR_FILENO, message, ft_strlen(message));
	return (-1);
}

void	*ptr_error(char *message)
{
	write(STDERR_FILENO, message, ft_strlen(message));
	return (NULL);
}
