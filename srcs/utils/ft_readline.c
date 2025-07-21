/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:13:00 by ebini             #+#    #+#             */
/*   Updated: 2025/07/21 22:15:10 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <unistd.h>

char	*ft_readline(char *prompt)
{
	if (isatty(0))
		return (readline(prompt));
	else
		return (readline(NULL));
}
