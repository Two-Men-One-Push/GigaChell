/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_debug.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:14:58 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/26 06:55:26 by ethebaul         ###   ########.fr       */
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

t_r_debug	*get_r_debug(void)
{
	const t_elf64_ehdr	*eh = elf_base(&get_r_debug);
	const t_elf64_phdr	*ph = (t_elf64_phdr *)((char *)eh + eh->e_phoff);
	t_elf64_dyn			*dyn;
	int					i;

	if (!elf_magic((t_elf64_ehdr *)eh) || !eh->e_phoff || !eh->e_phnum)
		return (NULL);
	i = 0;
	dyn = NULL;
	while (i < eh->e_phnum)
	{
		if (ph[i].p_type == PT_DYNAMIC)
		{
			dyn = (t_elf64_dyn *)((char *)eh + ph[i].p_vaddr);
			break ;
			++i;
		}
	}
	return (get_dt_debug_entry(dyn));
}
