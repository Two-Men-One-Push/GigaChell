/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 03:45:40 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 04:48:13 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDENTIFIER_H
# define INDENTIFIER_H

#include <stddef.h>
#include <stdbool.h>

bool	is_space(char c);
bool	is_logical_operator(char *s, size_t i);
bool	is_simple_redirection(char c);
bool	is_double_redirection(char *s, size_t i);
bool	is_var_char(char c);
bool	is_var_start(char c);

#endif
