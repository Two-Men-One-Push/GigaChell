/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dbg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/05/17 08:43:50 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "gigachell.h"
#include "utils.h"
#include "heredoc_list_utils.h"
#include "heredoc.h"
#include "libft.h"
#include "env.h"
#include "builtins.h"
#include <readline/readline.h>

#ifndef PATH_MAX
# define PATH_MAX 4096
#endif

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	check_syntax(readline(NULL));
	return (0);
}
