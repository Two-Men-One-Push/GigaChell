/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:57:56 by ebini             #+#    #+#             */
/*   Updated: 2025/06/25 18:49:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "utils.h"

int	int_error(char *message)
{
	(void)!write(STDERR_FILENO, message, ft_strlen(message));
	return (-1);
}

void	*ptr_error(char *message)
{
	(void)!write(STDERR_FILENO, message, ft_strlen(message));
	return (NULL);
}
