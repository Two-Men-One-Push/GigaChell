/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:57:02 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/19 17:20:25 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>
#include "readline_hack.h"
#include <term.h>

void	remove_duplicate(Keymap map, int index, void *addr)
{
	int	i;

	i = index + 1;
	while (i < KEYMAP_SIZE)
	{
		if ((map[i].type == ISKMAP
				|| map[i].type == ISMACR)
			&& map[i].function == addr)
			map[i].type = ISFUNC;
		++i;
	}
}

void	free_keymap(Keymap map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (i < KEYMAP_SIZE)
	{
		if (map[i].type == ISKMAP)
		{
			remove_duplicate(map, i, map[i].function);
			free_keymap((Keymap)map[i].function);
			if ((void *)map[i].function != emacs_meta_keymap
				&& (void *)map[i].function != emacs_ctlx_keymap)
				free((void **)(map[i].function));
		}
		else if (map[i].type == ISMACR)
		{
			remove_duplicate(map, i, map[i].function);
			free((void **)(map[i].function));
		}
		++i;
	}
}

void	tricky_free(void)
{
	struct s_line_state	*line_state_ptr;

	line_state_ptr = (struct s_line_state *)0x000000000046f460;
	free(line_state_ptr[0].lbreaks);
	free(line_state_ptr[0].lface);
	free(line_state_ptr[0].line);
	free(line_state_ptr[1].lbreaks);
	free(line_state_ptr[1].lface);
	free(line_state_ptr[1].line);
	free(*(void **)(0x00000000004706d0));
	free(*(void **)(0x00000000004706c8));
	free(*(void **)(0x0000000000470350));
	free(*(void **)(0x0000000000470348));
	free(*(void **)(0x000000000046f4e8));
	free(*(void **)(0x000000000046f4f0));
	free(*(void **)(0x000000000046f520));
	free(*(void **)(0x00000000004706d0));
}
//nm --demangle ./minishell | grep line_state_array
//nm --demangle ./minishell | grep _nc_cap_table
//nm --demangle ./minishell | grep _nc_info_table
//nm --demangle ./minishell | grep term_string_buffer
//nm --demangle ./minishell | grep term_buffer
//nm --demangle ./minishell | grep local_prompt
//nm --demangle ./minishell | grep local_prompt_prefix
//nm --demangle ./minishell | grep local_prompt_newlines
//nm --demangle ./minishell | grep _nc_cap_table

void	patch_readline_leaks(void)
{
	int					i;

	free(rl_prompt);
	free(rl_line_buffer);
	free(rl_executing_keyseq);
	free(rl_executing_macro);
	i = 0;
	while (funmap[i])
	{
		free(funmap[i]);
		++i;
	}
	free(funmap);
	free_keymap(emacs_standard_keymap);
	free_keymap(vi_movement_keymap);
	free_keymap(vi_insertion_keymap);
	tricky_free();
}
