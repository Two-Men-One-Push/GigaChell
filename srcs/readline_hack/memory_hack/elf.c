/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:40:33 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/08/25 22:33:05 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "readline_hack.h"

int	elf_magic(t_elf64_ehdr *eh)
{
	return (eh && eh->e_ident[EI_MAG0] == ELFMAG0
		&& eh->e_ident[EI_MAG1] == ELFMAG1
		&& eh->e_ident[EI_MAG2] == ELFMAG2
		&& eh->e_ident[EI_MAG3] == ELFMAG3);
}

void	*elf_base(void *any_addr)
{
	t_elf64_ehdr	*eh;
	unsigned long	p;
	int				i;

	p = (unsigned long)any_addr & ~(unsigned long)(PAGE_SIZE - 1);
	i = 0;
	while (i < MAX_PAGES_SCAN)
	{
		eh = (t_elf64_ehdr *)p;
		if (elf_magic(eh))
		{
			return ((void *)p);
		}
		p -= PAGE_SIZE;
		++i;
	}
	return (NULL);
}

void	*find_elf_byname(const char *needle)
{
	char		*name;
	t_r_debug	*rd;
	t_link_map	*lm;

	rd = get_r_debug(elf_base((void *)&find_elf_byname));
	if (!rd)
		return (NULL);
	lm = rd->r_map;
	while (lm)
	{
		name = lm->l_name;
		if (name && *name)
		{
			if (ft_strstr(name, needle))
				return ((void *)(unsigned long)lm->l_addr);
		}
		lm = lm->l_next;
	}
	return (NULL);
}
