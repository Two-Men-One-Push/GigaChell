/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_readline_leaks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:57:02 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/23 07:48:38 by ethebaul         ###   ########.fr       */
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

void	free_tinfo_internal(void)
{
	char		*base;

	base = find_elf_byname("libtinfo");
	printf("ncurses at -> %p\n", base);
	free(*(void **)(base + 0x46b50));
}

void	free_readline_internal(void)
{
	char	*base;

	base = find_elf_byname("libreadline");
	printf("readline at -> %p\n", base);
	free(*(void **)(base + 0x60708));
	free(*(void **)(base + 0x60710));
}

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
	free_tinfo_internal();
}
