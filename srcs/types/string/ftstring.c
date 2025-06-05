/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:10:07 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 19:18:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "tstring.h"

t_string	ftstring(char *str, size_t size)
{
	t_string	string;

	string.ptr = str;
	string.size = size;
	return (string);
}
