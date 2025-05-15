/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stref.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:51:38 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/14 19:53:08 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STREF_H
# define T_STREF_H

# include "t_size.h"

typedef struct s_stref
{
	char	*ptr;
	t_size	size;
}	t_stref;

#endif