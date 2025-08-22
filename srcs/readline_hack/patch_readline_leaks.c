/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_readline_leaks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:57:02 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/22 09:57:06 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>
#include "readline_hack.h"

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

void	free_readline_internal(void)
{
	const void		*bss = get_bss(find_elf_byname("libreadline"));
	t_line_state	*line_state_array;

	line_state_array = (t_line_state *)(bss + 0xa0);
	printf("line_state_array at -> %p\n", line_state_array);
	// free(line_state_array[0].lbreaks);
	// free(line_state_array[0].lface);
	// free(line_state_array[0].line);
	// free(line_state_array[0].wrapped_line);
	// free(line_state_array[1].lbreaks);
	// free(line_state_array[1].lface);
	// free(line_state_array[1].line);
	// free(line_state_array[1].wrapped_line);
}
//nm --demangle ./minishell | grep line_state_array
//nm --demangle ./minishell | grep _nc_cap_table
//nm --demangle ./minishell | grep _nc_info_table
//nm --demangle ./minishell | grep term_string_buffer
//nm --demangle ./minishell | grep term_buffer
//nm --demangle ./minishell | grep local_prompt
//nm --demangle ./minishell | grep local_prompt_prefix
//nm --demangle ./minishell | grep local_prompt_newlines

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
	free_readline_internal();
}
