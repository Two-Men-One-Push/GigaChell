/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:55:36 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/14 20:02:17 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	syntax_error(t_stref	stref)
{
	write(2, "GigaChell: syntax error near unexpected token `", 47);
	write(2, stref.ptr, stref.size);
	write(2, "'\n", 2);
	return (1);
}
