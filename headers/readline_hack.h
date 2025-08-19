/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:58:25 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/19 02:38:21 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_HACK_H
# define READLINE_HACK_H

#include <readline/readline.h>
#include <stdlib.h>

void    free_keymap(Keymap map);
void    hackpatch_readline_leaks(void);
void    remove_duplicate(Keymap map, int index, void *addr);

struct s_line_state
{
    char    *line;
    char    *lface;
    int        *lbreaks;
    int        lbsize;
};

struct s_termtype
{
    char            *term_names;
    char            *str_table;
    char            *Booleans;
    short            *Numbers;
    char            **Strings;
    char            *ext_str_table;
    char            **ext_Names;
    unsigned short    num_Booleans;
    unsigned short    num_Numbers;
    unsigned short    num_Strings;
    unsigned short    ext_Booleans;
    unsigned short    ext_Numbers;
    unsigned short    ext_Strings;
};

struct s_term
{
    struct s_termtype    type;
};

#endif