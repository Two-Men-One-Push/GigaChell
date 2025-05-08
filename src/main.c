/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/05/08 15:28:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>

#include "env.h"
#include "constants.h"

int	main(int ac, char **av, char **envp)
{
	char	*line;
	int		status_code;

	(void)ac;
	(void)av;
	ft_initenv(envp);
	line = readline(PROMPT);
	while (line)
	{
		status_code = exec_pipe(line);
		free(line);
		line = readline(PROMPT);
	}
}
