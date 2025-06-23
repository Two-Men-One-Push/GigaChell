/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:57:14 by ebini             #+#    #+#             */
/*   Updated: 2025/06/23 08:24:48 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stddef.h>

# include "defs/hd_node.h"

char	*str_extract(char *start, size_t len);

void	secure_close(int fd);

bool	skip_paranthesis(char *s, size_t *i);
void	clear_paranthesis(char *s, size_t *i, t_hd_node **heredoc_list);
bool	skip_dquote(char *s, size_t *i);
bool	skip_squote(char *s, size_t *i);

char	*get_redirect_file(char *arg, size_t *arg_len);
char	*get_limiter(char *cmd, size_t *i);

void	str_unquote(char *s);

/**
 * @brief Open a temporary file with flag permission and returns its fd.
 * @param path The path that will be set to unsync the temporary file
 * @param flags The the flags used to open the new file with open() (from
 * fcntl.h)
 * @warning The memory newly pointed by *path should be released using free().
 * @return A new fd pointing to a new file in r/w right access.
 */
int		tmp_fd(char **path, int flags);

void	print_tab_free(char **tab);

#endif
