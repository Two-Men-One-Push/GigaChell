/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 03:45:40 by ebini             #+#    #+#             */
/*   Updated: 2025/06/15 02:39:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFIER_H
# define IDENTIFIER_H

# include <stddef.h>
# include <stdbool.h>

bool	is_space(char c);
bool	is_logical_operator(char *s, size_t i);
bool	is_simple_redirection(char c);
bool	is_double_redirection(char *s, size_t i);
bool	is_limiter_char(char c);
bool	is_var_char(char c);
bool	is_var_start(char c);

#endif
