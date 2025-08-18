/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:56:44 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/18 19:15:30 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_HACK_H
# define READLINE_HACK_H

struct s_line_state
{
	char	*line;
	char	*lface;
	int		*lbreaks;
	int		lbsize;
};

void	readline_clean_hack(void);

#endif