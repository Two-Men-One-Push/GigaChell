/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:55:46 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/18 19:23:47 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_hack.h"
#include <stdlib.h>

void	readline_clean_hack(void)
{
	struct s_line_state	*line_state_ptr;

	line_state_ptr = (struct s_line_state *)(0x000000000046f460);
	free(line_state_ptr[0].lbreaks);
	free(line_state_ptr[0].lface);
	free(line_state_ptr[0].line);
	free(line_state_ptr[1].lbreaks);
	free(line_state_ptr[1].lface);
	free(line_state_ptr[1].line);
}
