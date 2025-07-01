/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:38:19 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 15:42:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_UTILS_H
# define BUILTINS_UTILS_H

# include <stdbool.h>
# include <stddef.h>

void	remove_path_dot(char *path, size_t i);
void	remove_path_dot_dot(char *path, size_t *i);
void	clean_path_slash(char *path, size_t i);
void	handle_path_end(char *path, size_t i);
int		secure_pwd(void);

#endif
