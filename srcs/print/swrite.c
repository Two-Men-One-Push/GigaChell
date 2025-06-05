/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swrite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:04:36 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 19:18:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

int	swrite(int fd, char *str, size_t len, int ret)
{
	if (write(fd, str, len) == -1)
		write(2, "write error\n", 13);
	return (ret);
}
