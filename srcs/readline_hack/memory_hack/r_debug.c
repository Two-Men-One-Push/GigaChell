/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_debug.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:14:58 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/22 09:15:12 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_hack.h"

t_r_debug	*get_r_debug(void *base)
{
	t_elf64_ehdr	*eh;
	t_elf64_phdr	*ph;
	t_elf64_dyn		*dyn;
	int				i;

	if (!base)
		return (NULL);
	eh = (t_elf64_ehdr *)base;
	if (!elf_magic(eh) || eh->e_phoff == 0 || eh->e_phnum == 0)
		return (NULL);
	ph = (t_elf64_phdr *)((char *)base + eh->e_phoff);
	dyn = NULL;
	i = 0;
	while (i < eh->e_phnum && ph[i].p_type != PT_DYNAMIC)
		++i;
	if (ph[i].p_type == PT_DYNAMIC)
		dyn = (t_elf64_dyn *)((char *)base + ph[i].p_vaddr);
	if (!dyn)
		return (NULL);
	while (dyn->d_tag != DT_NULL && dyn->d_tag != DT_DEBUG)
		++dyn;
	if (dyn->d_tag == DT_DEBUG)
		return ((t_r_debug *)(unsigned long)dyn->u_d.ptr);
	return (NULL);
}
