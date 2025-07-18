/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:54:35 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/16 20:57:20 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "redirect_fd.h"
#include <sys/stat.h>
#include <unistd.h>
#include "builtins_utils.h"

int	ft_pwd(int argc, char **argv, t_redirect_fd *redirect)
{
	(void)argc;
	(void)argv;
	if (!getcwd(NULL, 0))
		ft_dprintf(redirect->out, "%s\n", ft_getenv("PWD"));
	else if (secure_pwd())
		return (1);
	else
		ft_dprintf(redirect->out, "%s\n", ft_getenv("PWD"));
	return (0);
}
