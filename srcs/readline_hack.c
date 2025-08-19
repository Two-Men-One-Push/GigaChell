/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:57:02 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/19 02:38:16 by CyberOneFR       ###   ########.fr       */
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
		if ((map[i].type == ISKMAP || map[i].type == ISMACR) && map[i].function == addr)
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
				free(map[i].function);
		}
		else if (map[i].type == ISMACR)
		{
			remove_duplicate(map, i, map[i].function);
			free(map[i].function);
		}
		++i;
	}
}

void	hackpatch_readline_leaks(void)
{
	struct s_line_state	*line_state_ptr;
	struct s_term		*cur_term_ptr;
	int	i;

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
	line_state_ptr = (struct s_line_state *)0x0000000000471480;//nm --demangle ./minishell | grep line_state
	free(line_state_ptr[0].lbreaks);
	free(line_state_ptr[0].lface);
	free(line_state_ptr[0].line);
	free(line_state_ptr[1].lbreaks);
	free(line_state_ptr[1].lface);
	free(line_state_ptr[1].line);
	cur_term_ptr = (struct s_term *)0x0000000000472608;//nm --demangle ./minishell | grep cur_term
	printf("[%p]\n", cur_term_ptr->type.str_table);
	// free(cur_term_ptr->type.str_table);
	printf("[%p]\n", cur_term_ptr->type.Booleans);
	// free(cur_term_ptr->type.Booleans);
	printf("[%p]\n", cur_term_ptr->type.Numbers);
	// free(cur_term_ptr->type.Numbers);
	printf("[%p]\n", cur_term_ptr->type.term_names);
	// free(cur_term_ptr->type.term_names);
	i = 0;
	while (cur_term_ptr->type.term_names[i])
	{
		printf("term_names[%d]\n", (unsigned char)cur_term_ptr->type.term_names[i]);
		++i;
	}
	printf("[%p]\n", cur_term_ptr->type.Strings);
	// free(cur_term_ptr->type.Strings);
	printf("[%p]\n", cur_term_ptr->type.ext_str_table);
	// free(cur_term_ptr->type.ext_str_table);
	printf("[%p]\n", cur_term_ptr->type.ext_Names);
	// free(cur_term_ptr->type.ext_Names);
	free(*(void **)(0x0000000000472768));//nm --demangle ./minishell | grep _nc_cap_table
	free(*(void **)(0x0000000000472748));//nm --demangle ./minishell | grep _nc_info_table
	free(*(void **)(0x00000000004723c0));//nm --demangle ./minishell | grep term_string_buffer
	free(*(void **)(0x00000000004723b8));//nm --demangle ./minishell | grep term_buffer
	free(*(void **)(0x0000000000471508));//nm --demangle ./minishell | grep local_prompt
	free(*(void **)(0x0000000000471510));//nm --demangle ./minishell | grep local_prompt_prefix
	free(*(void **)(0x0000000000471540));//nm --demangle ./minishell | grep local_prompt_newlines
	free(*(void **)(0x0000000000472398));//nm --demangle ./minishell | grep _rl_active_region_start_color
	free(*(void **)(0x00000000004723a0));//nm --demangle ./minishell | grep _rl_active_region_end_color
	free(*(void **)(0x0000000000472750));//nm --demangle ./minishell | grep _nc_cap_table
}