/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_debug.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:14:58 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/24 22:00:29 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_hack.h"

t_r_debug	*get_dt_debug_entry(t_elf64_dyn *dyn)
{
	if (!dyn)
		return (NULL);
	while (dyn->d_tag != DT_NULL)
	{
		if (dyn->d_tag == DT_DEBUG)
			return ((t_r_debug *)dyn->u_d.ptr);
		++dyn;
	}
	return (NULL);
}

t_r_debug	*get_r_debug(void *base)
{
	t_elf64_ehdr	*eh;
	t_elf64_phdr	*ph;
	t_elf64_dyn		*dyn;
	int				i;

	eh = (t_elf64_ehdr *)base;
	if (!base || !elf_magic(eh) || !eh->e_phoff || !eh->e_phnum)
		return (NULL);
	ph = (t_elf64_phdr *)((char *)base + eh->e_phoff);
	printf("ph at -> %p\n", (void *)ph);
	dyn = NULL;
	i = 0;
	while (i < eh->e_phnum && ph[i].p_type != PT_DYNAMIC)
	{
		if (ph[i].p_type == PT_DYNAMIC)
		{
			if (eh->e_type == ET_EXEC)
				dyn = (t_elf64_dyn *)((char *)base + ph[i].p_vaddr);
			else if (eh->e_type == ET_DYN)
				dyn = (t_elf64_dyn *)((char *)base + ph[i].p_offset);
			break ;
		}
		++i;
	}
	return (get_dt_debug_entry(dyn));
}
