/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:04:18 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/25 19:43:18 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "tchain.h"

char	**expand(char *cmd, int status);
size_t	strtotab_len(char *str, size_t len);
char	**strtotab(char *str, size_t len);
int		tab_check(char **tab, size_t i);
size_t	expand_var_len(char **cmd, int status);
size_t	expand_len(char *cmd, int status);
void	expand_var_fill(char **tab, char **cmd, int dquote, int status);
void	expand_fill(char *tab, char *cmd, int status);

#endif