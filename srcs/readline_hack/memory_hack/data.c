/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 06:21:47 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/26 06:11:27 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_hack.h"

void	*get_seg_data(void *base)
{
	t_elf64_ehdr	*eh;
	t_elf64_phdr	*ph;
	int				i;

	if (!base)
		return (NULL);
	eh = (t_elf64_ehdr *)base;
	if (!elf_magic(eh))
		return (NULL);
	ph = (t_elf64_phdr *)((char *)base + eh->e_phoff);
	i = 0;
	while (i < eh->e_phnum)
	{
		if (ph[i].p_type == PT_LOAD && (ph[i].p_flags & PF_W))
			return ((void *)((char *)base + ph[i].p_vaddr));
		++i;
	}
	return (NULL);
}

unsigned long	get_seg_data_size(void *base)
{
	t_elf64_ehdr	*eh;
	t_elf64_phdr	*ph;
	int				i;

	if (!base)
		return (0);
	eh = (t_elf64_ehdr *)base;
	if (!elf_magic(eh))
		return (0);
	ph = (t_elf64_phdr *)((char *)base + eh->e_phoff);
	i = 0;
	while (i < eh->e_phnum)
	{
		if (ph[i].p_type == PT_LOAD && (ph[i].p_flags & PF_W))
			return (ph[i].p_memsz);
		++i;
	}
	return (0);
}
