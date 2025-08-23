/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 06:21:47 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/23 04:39:24 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_hack.h"

void	*get_bss(void *base)
{
	t_elf64_ehdr	*eh;
	t_elf64_phdr	*ph;
	unsigned long	seg_base;
	unsigned long	data_end;
	int				i;

	eh = (t_elf64_ehdr *)base;
	if (!base)
		return (NULL);
	if (!elf_magic(eh))
		return (NULL);
	ph = (t_elf64_phdr *)((char *)base + eh->e_phoff);
	i = 0;
	while (i < eh->e_phnum)
	{
		if (ph[i].p_type == PT_LOAD && (ph[i].p_flags & PF_W))
		{
			seg_base = (unsigned long)base + ph[i].p_vaddr;
			data_end = seg_base + ph[i].p_filesz;
			return ((void *)data_end);
		}
		++i;
	}
	return (NULL);
}
