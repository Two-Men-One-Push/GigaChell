/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_readline_section.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:19:30 by ethebaul          #+#    #+#             */
/*   Updated: 2025/08/19 22:05:33 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_hack.h"

struct s_elf64_ehdr	*find_elf_header(void *addr)
{
	struct s_elf64_ehdr	*ehdr;
	unsigned long		base;

	base = (unsigned long)addr & ~(0xFFFUL);
	while (base > 0x1000)
	{
		printf("checking for ELF header at -> %p\n", (void *)base);
		if (*((unsigned int *)base) == 0x464C457F)
		{
			ehdr = (struct s_elf64_ehdr *)base;
			if (ehdr->e_ident[EI_CLASS] == ELFCLASS64 && ehdr->e_type == ET_DYN)
				return (ehdr);
		}
		base -= 0x1000;
	}
	return (NULL);
}

void	*find_bss_start(void *addr)
{
	struct s_elf64_ehdr	*ehdr;
	struct s_elf64_phdr	*phdr;
	unsigned long		bss_start;
	unsigned long		base;
	int					i;

	ehdr = find_elf_header(addr);
	if (!ehdr)
		return (NULL);
	phdr = (struct s_elf64_phdr *)((char *)ehdr + ehdr->e_phoff);
	i = 0;
	while (i < ehdr->e_phnum)
	{
		if (phdr[i].p_type == PT_LOAD && (phdr[i].p_flags & PF_W))
		{
			base = (unsigned long)ehdr;
			bss_start = base + phdr[i].p_vaddr + phdr[i].p_filesz;
			return ((void *)bss_start);
		}
		++i;
	}
	return (NULL);
}
