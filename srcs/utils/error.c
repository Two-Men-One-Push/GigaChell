/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:57:56 by ebini             #+#    #+#             */
/*   Updated: 2025/06/27 19:03:46 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "utils.h"

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
