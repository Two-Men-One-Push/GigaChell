/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:54:35 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/30 15:41:10 by ethebaul         ###   ########.fr       */
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
	if (secure_pwd())
		return (1);
	ft_dprintf(redirect->out, "%s\n", ft_getenv("PWD"));
	return (0);
}
