/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:58:25 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/23 07:55:33 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_HACK_H
# define READLINE_HACK_H

# include <readline/readline.h>

# define PT_LOAD 1
# define PF_W 2
# define PT_DYNAMIC 2

# define ELFCLASS64 2
# define ET_DYN 3
# define EI_CLASS 4

# define EI_MAG0 0
# define EI_MAG1 1
# define EI_MAG2 2
# define EI_MAG3 3
# define ELFMAG0 0x7f
# define ELFMAG1 'E'
# define ELFMAG2 'L'
# define ELFMAG3 'F'

# define DT_NULL 0
# define DT_DEBUG 21

# define PAGE_SIZE 0x1000
# define MAX_PAGES_SCAN 65536

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

typedef struct s_elf64_ehdr
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
}	t_elf64_ehdr;

typedef struct s_elf64_phdr
{
	t_elf64_word	p_type;
	t_elf64_word	p_flags;
	t_elf64_off		p_offset;
	t_elf64_addr	p_vaddr;
	t_elf64_addr	p_paddr;
	t_elf64_xword	p_filesz;
	t_elf64_xword	p_memsz;
	t_elf64_xword	p_align;
}	t_elf64_phdr;

typedef struct s_line_state
{
	char	*line;
	char	*lface;
	int		*lbreaks;
	int		lbsize;
	int		wbsize;
	int		*wrapped_line;
}	t_line_state;

typedef struct s_elf64_dyn
{
	t_elf64_sword	d_tag;
	union
	{
		t_elf64_word	val;
		t_elf64_addr	ptr;
	}	u_d;
}	t_elf64_dyn;

typedef struct link_map
{
	t_elf64_addr	l_addr;
	char			*l_name;
	t_elf64_addr	*l_ld;
	struct link_map	*l_next;
	struct link_map	*l_prev;
}	t_link_map;

typedef struct r_debug
{
	int				r_version;
	struct link_map	*r_map;
	t_elf64_addr	r_brk;
	enum
	{
		RT_CONSISTENT,
		RT_ADD,
		RT_DELETE
	}	e_r_state;
	t_elf64_addr	r_ldbase;
}	t_r_debug;

typedef struct s_termtype
{
	char			*term_names;
	char			*str_table;
	char			*booleans;
	short			*numbers;
	char			**strings;
	char			*ext_str_table;
	char			**ext_names;
	unsigned short	num_booleans;
	unsigned short	num_numbers;
	unsigned short	num_strings;
	unsigned short	ext_booleans;
	unsigned short	ext_numbers;
	unsigned short	ext_strings;
}	t_termtype;

typedef struct s_term
{
	t_termtype	type;
}	t_term;

int			elf_magic(t_elf64_ehdr *eh);
void		*elf_base(void *any_code_addr);

t_r_debug	*get_r_debug(void *base);
void		*find_elf_byname(const char *needle);
void		*get_bss(void *base);

void		free_keymap(Keymap map);
void		patch_readline_leaks(void);
void		remove_duplicate(Keymap map, int index, void *addr);

#endif