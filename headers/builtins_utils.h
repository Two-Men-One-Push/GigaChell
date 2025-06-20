/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:38:19 by ebini             #+#    #+#             */
/*   Updated: 2025/05/15 20:28:01 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_UTILS_H
# define BUILTINS_UTILS_H

bool	are_same_path(const char *path1, const char *path2);
void	remove_path_dot(char *path, size_t i);
void	remove_path_dot_dot(char *path, size_t *i);
void	clean_path_slash(char *path, size_t i);
void	handle_path_end(char *path, size_t i);

#endif
