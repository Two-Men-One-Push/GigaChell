/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:58:25 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/19 16:50:25 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_HACK_H
# define READLINE_HACK_H

# include <readline/readline.h>

void	free_keymap(Keymap map);
void	patch_readline_leaks(void);
void	remove_duplicate(Keymap map, int index, void *addr);

struct s_line_state
{
	char	*line;
	char	*lface;
	int		*lbreaks;
	int		lbsize;
	int		wbsize;
	int		*wrapped_line;
};

#endif