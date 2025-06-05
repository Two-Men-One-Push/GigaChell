/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:04:03 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 19:14:02 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TSTRING_H
# define TSTRING_H

# include <stddef.h>

typedef struct s_string
{
	size_t	size;
	char	*ptr;
}	t_string;

size_t		ftstrlen(char *str);
t_string	ftstring(char *str, size_t size);
int			skipto(t_string string, size_t *index, char c);

#endif