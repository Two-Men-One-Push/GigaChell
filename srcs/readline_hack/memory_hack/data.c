/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 06:21:47 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/25 22:14:46 by ethebaul         ###   ########.fr       */
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
		{
			printf("data segment at -> %p\n", (void *)((char *)base + ph[i].p_vaddr));
			return ((void *)((char *)base + ph[i].p_vaddr));
		}
		++i;
	}
	return (NULL);
}
