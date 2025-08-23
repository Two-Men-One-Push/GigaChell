/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_hack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:58:25 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/23 15:35:46 by ethebaul         ###   ########.fr       */
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

# define NCCS 32
# define TGETENT_MAX 4
# define NUM_PARM 9

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
typedef unsigned char	t_cc_t;
typedef unsigned int	t_tcflag_t;
typedef unsigned int	t_speed_t;
typedef unsigned short	t_otcflag_t;
typedef unsigned char	t_ospeed_t;

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
	unsigned short	num_inteans;
	unsigned short	num_numbers;
	unsigned short	num_strings;
	unsigned short	ext_inteans;
	unsigned short	ext_numbers;
	unsigned short	ext_strings;
}	t_termtype;

typedef struct s_stack_frame
{
	union
	{
		int		num;
		char	*str;
	} u_data;
	int	num_type;
}	t_stack_frame;

typedef struct s_tparm_state
{
	const char		*tparam_base;
	t_stack_frame	stack[20];
	int				stack_ptr;
	char			*out_buff;
	size_t			out_size;
	size_t			out_used;
	char			*fmt_buff;
	size_t			fmt_size;
	int				static_vars[26];
	const char		*tname;
}	t_parm_state;

typedef struct s_termios
{
	t_tcflag_t		c_iflag;
	t_tcflag_t		c_oflag;
	t_tcflag_t		c_cflag;
	t_tcflag_t		c_lflag;
	char			c_line;
	t_cc_t			c_cc[NCCS];
	t_speed_t		c_ispeed;
	t_speed_t		c_ospeed;
}	t_termios;

typedef struct s_term
{
	t_termtype		type;
	short			filedes;
	t_termios		ot_termiosb;
	t_termios		nt_termiosb;
	int				_baudrate;
	char			*_termname;
	t_parm_state	tparm_state;
}	t_term;

typedef struct s_tgetent_cache
{
	long	sequence;
	int		last_used;
	char	*fix_sgr0;
	char	*last_bufp;
	t_term	*last_term;
}	t_tgetent_cache;

typedef struct s_iterators_vars
{
	const char	*name;
	char		*value;
}	t_iterators_vars;

typedef struct s_ldat
{
	int		*text;
	short	firstchar;
	short	lastchar;
	short	oldindex;
}	t_ldat;

typedef struct s_win_st
{
	short			_cury;
	short			_curx;
	short			_maxy;
	short			_maxx;
	short			_begy;
	short			_begx;
	short			_flags;
	unsigned int	_attrs;
	unsigned int	_bkgd;
	char			_notimeout;
	char			_clear;
	char			_leaveok;
	char			_scroll;
	char			_idlok;
	char			_idcok;
	char			_immed;
	char			_sync;
	char			_use_keypad;
	int				_delay;
	struct ldat		*_line;
	short			_regtop;
	short			_regbottom;
	int				_parx;
	int				_pary;
	struct _win_st	*_parent;
	struct
	{
		short	_pad_y;
		short	_pad_x;
		short	_pad_top;
		short	_pad_left;
		short	_pad_bottom;
		short	_pad_right;
	}	s_pad;
	short			_yoffset;
}	t_win_st;

typedef struct s_ncglob
{
	int					have_sigtstp;
	int					have_sigwinch;
	int					cleanup_nested;
	char				init_signals;
	char				init_screen;
	char				*comp_sourcename;
	char				*comp_termtype;
	char				have_tic_directory;
	char				keep_tic_directory;
	const char			*tic_directory;
	char				*dbi_list;
	int					dbi_size;
	char				*first_name;
	char				**keyname_table;
	int					init_keyname;
	int					slk_format;
	int					getstr_limit;
	char				*safeprint_buf;
	size_t				safeprint_used;
	t_tgetent_cache		tgetent_cache[TGETENT_MAX];
	int					tgetent_index;
	long				tgetent_sequence;
	char				*dbd_blob;
	char				**dbd_list;
	int					dbd_size;
	long				dbd_time;
	t_iterators_vars	dbd_vars[6];
	void				*cached_tparm;
	int					count_tparm;
	t_win_st			*_nc_windowlist;
	char				*home_terminfo;
	int					safeprint_cols;
	int					safeprint_rows;
}	t_ncurses_globals;

typedef struct s_tparm_data
{
	const char	*format;
	int			num_actual;
	int			tparm_type;
	int			num_parsed;
	int			num_popped;
	long		param[NUM_PARM];
	char		*p_is_s[NUM_PARM];
}	t_tparm_data;

int			elf_magic(t_elf64_ehdr *eh);
void		*elf_base(void *any_code_addr);

t_r_debug	*get_r_debug(void *base);
void		*find_elf_byname(const char *needle);
void		*get_bss(void *base);

void		free_keymap(Keymap map);
void		remove_duplicate(Keymap map, int index, void *addr);

void		free_nc_global(const void *base);
void		free_tinfo_internal(void);
void		free_readline_internal(void);

void		patch_readline_leaks(void);

#endif