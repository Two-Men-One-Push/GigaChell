/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tchain.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 07:06:32 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/27 19:16:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCHAIN_H
# define TCHAIN_H

# include <stddef.h>

typedef struct s_chain_link
{
	struct s_chain_link	*prev;
	struct s_chain_link	*next;
	void				*data;
}	t_chain_link;

typedef struct s_chain
{
	t_chain_link	*start;
	t_chain_link	*end;
	size_t			size;
}	t_chain;

t_chain			chain_init(void);
int				chain_append(t_chain *chain, t_chain_link *link);
void			chain_free(t_chain *chain);

t_chain_link	chain_link_init(void *data);
t_chain_link	*chain_link_new(void *data);

#endif