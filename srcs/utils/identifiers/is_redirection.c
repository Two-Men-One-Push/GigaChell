/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isredirection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 04:03:47 by ebini             #+#    #+#             */
/*   Updated: 2025/05/14 04:09:31 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

bool	is_simple_redirection(char c)
{
	return (c == '>' || c == '<');
}

bool	is_double_redirection(char *s, size_t i)
{
	return ((s[i] == '<' && s[i + 1] == '<')
		|| (s[i] == '>' && s[i + 1] == '>'));
}
