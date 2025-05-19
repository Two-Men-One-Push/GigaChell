/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:54:03 by ebini             #+#    #+#             */
/*   Updated: 2025/05/17 07:36:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	secure_close(int fd)
{
	if (close(fd))
		write(STDERR_FILENO, "Warning: Couldn't close fd\n", 27);
}
