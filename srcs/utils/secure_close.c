/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:54:03 by ebini             #+#    #+#             */
/*   Updated: 2025/06/25 18:15:39 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	secure_close(int fd)
{
	if (close(fd))
		write(STDERR_FILENO, "Warning: Couldn't close fd\n", 27);
}
