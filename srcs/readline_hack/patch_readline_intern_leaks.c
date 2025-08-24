/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_readline_intern_leaks.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:27:54 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/23 18:05:32 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>
#include "readline_hack.h"

void	free_nc_global(const void *base)
{
	const t_ncurses_globals	*nc_globals = (void *)(base + 0x46680);

	free(nc_globals->_nc_windowlist);
	free(nc_globals->dbd_blob);
	free(nc_globals->dbd_list);
	free(nc_globals->comp_sourcename);
	free(nc_globals->home_terminfo);
	free(nc_globals->tgetent_cache[0].fix_sgr0);
	free(nc_globals->tgetent_cache[1].fix_sgr0);
	free(nc_globals->tgetent_cache[2].fix_sgr0);
	free(nc_globals->tgetent_cache[3].fix_sgr0);
	free(nc_globals->dbd_vars[0].value);
	free(nc_globals->dbd_vars[1].value);
	free(nc_globals->dbd_vars[2].value);
	free(nc_globals->dbd_vars[3].value);
	free(nc_globals->dbd_vars[4].value);
	free(nc_globals->dbd_vars[5].value);
	free((void *)(*(t_tparm_data **)nc_globals->cached_tparm)->format);
	free((void *)*(t_tparm_data **)nc_globals->cached_tparm);
	free((void *)(t_tparm_data *)nc_globals->cached_tparm);
}

void	free_tinfo_internal(void)
{
	const char				*base = find_elf_byname("libtinfo");
	const t_term			*cur_term = *(t_term **)(base + 0x46da8 - 0xfe0);

	printf("tinfo address at -> %p\n", base);
	free(*(void **)(base + 0x46b50 - 0xfe0));
	free(cur_term->type.term_names);
	free(cur_term->type.ext_names);
	free(cur_term->type.booleans);
	free(cur_term->type.ext_str_table);
	free(cur_term->type.numbers);
	free(cur_term->type.strings);
	free(cur_term->tparm_state.fmt_buff);
	free(cur_term->tparm_state.out_buff);
	free(cur_term->_termname);
	free((void *)cur_term);
	free_nc_global(base);
}

void	free_readline_internal(void)
{
	const char			*base = find_elf_byname("libreadline");
	const t_line_state	*line_state = (t_line_state *)(base + 0x5f820);

	printf("readline address at -> %p\n", base);
	free(*(void **)(base + 0x60708 + 0x138));
	free(*(void **)(base + 0x60710 + 0x138));
	free(line_state[0].line);
	free(line_state[0].lbreaks);
	free(line_state[0].lface);
	free(line_state[0].wrapped_line);
	free(line_state[1].line);
	free(line_state[1].lbreaks);
	free(line_state[1].lface);
	free(line_state[1].wrapped_line);
	free(*(void **)(base + 0x5f8a8 + 0x138));
	free(*(void **)(base + 0x5f8e0 + 0x138));
	free(*(void **)(base + 0x5f730 + 0x138));
	free(*(void **)(base + 0x5f748 + 0x138));
	free(*(void **)(base + 0x60820 + 0x138));
	free(*(void **)(base + 0x60800 + 0x138));
}
