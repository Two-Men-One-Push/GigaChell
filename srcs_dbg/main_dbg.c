/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dbg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:05:38 by ebini             #+#    #+#             */
/*   Updated: 2025/06/05 19:11:52 by ethebaul         ###   ########.fr       */
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
	return (0);
}
