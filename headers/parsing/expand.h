/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:04:18 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/15 05:03:07 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "tchain.h"

int		arg_split(t_chain *chain, char *cmd);
char	*extract(char *src, size_t size);
int		arg_extract(char *cmd, size_t *i, t_chain *chain);
int		arg_split(t_chain *chain, char *cmd);
int		split_expanded_arg(t_chain *chain, t_chain_link *link);
int		expand_var(char **str);

#endif