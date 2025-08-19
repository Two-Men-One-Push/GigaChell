/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:58:25 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/19 21:49:14 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_HACK_H
# define READLINE_HACK_H

# include <readline/readline.h>

# define PT_LOAD 1
# define PF_W 2
# define ELFCLASS64 2
# define ET_DYN 3
# define EI_CLASS 4

typedef unsigned short	t_elf32_half;
typedef unsigned short	t_elf64_half;
typedef unsigned int	t_elf32_word;
typedef int				t_elf32_sword;
typedef unsigned int	t_elf64_word;
typedef int				t_elf64_sword;
typedef unsigned long	t_elf32_xword;
typedef long			t_elf32_sxword;
typedef unsigned long	t_elf64_xword;
typedef long			t_elf64_sxword;
typedef unsigned int	t_elf32_addr;
typedef unsigned long	t_elf64_addr;
typedef unsigned int	t_elf32_off;
typedef unsigned long	t_elf64_off;
typedef unsigned short	t_elf32_section;
typedef unsigned short	t_elf64_section;
typedef t_elf32_half	t_elf32_versym;
typedef t_elf64_half	t_elf64_versym;

struct	s_elf64_ehdr
{
	unsigned char	e_ident[16];
	t_elf64_half	e_type;
	t_elf64_half	e_machine;
	t_elf64_word	e_version;
	t_elf64_addr	e_entry;
	t_elf64_off		e_phoff;
	t_elf64_off		e_shoff;
	t_elf64_word	e_flags;
	t_elf64_half	e_ehsize;
	t_elf64_half	e_phentsize;
	t_elf64_half	e_phnum;
	t_elf64_half	e_shentsize;
	t_elf64_half	e_shnum;
	t_elf64_half	e_shstrndx;
};

struct s_elf64_phdr
{
	t_elf64_word	p_type;
	t_elf64_word	p_flags;
	t_elf64_off		p_offset;
	t_elf64_addr	p_vaddr;
	t_elf64_addr	p_paddr;
	t_elf64_xword	p_filesz;
	t_elf64_xword	p_memsz;
	t_elf64_xword	p_align;
};

struct s_line_state
{
	char	*line;
	char	*lface;
	int		*lbreaks;
	int		lbsize;
	int		wbsize;
	int		*wrapped_line;
};

void				free_keymap(Keymap map);
void				patch_readline_leaks(void);
void				remove_duplicate(Keymap map, int index, void *addr);
struct s_elf64_ehdr	*find_elf_header(void *addr);
void				*find_bss_start(void *addr);

#endif