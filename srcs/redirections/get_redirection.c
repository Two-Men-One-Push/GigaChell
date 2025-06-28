/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:57:08 by ebini             #+#    #+#             */
/*   Updated: 2025/06/28 06:47:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#include "defs/hd_node.h"
#include "defs/redirect_fd.h"
#include "heredoc_list_utils.h"
#include "identifier.h"
#include "utils.h"
#include "libft.h"

#include <stdio.h>

static int	redirect_in(char *cmd, size_t *i, t_redirect_fd *redirect)
{
	char	*arg_start;
	char	*file;
	size_t		arg_len;

	arg_start = cmd + *i;
	file = get_redirect_file(arg_start, &arg_len);
	if (!file)
		return (1);
	if (redirect->in > -1)
		secure_close(redirect->in);
	redirect->in = open(file, O_RDONLY);
	if (redirect->in == -1)
	{
		ft_dprintf(2, "open: %s: %s\n", file, strerror(errno));
		free(file);
		return (1);
	}
	free(file);
	ft_memset(arg_start, ' ', arg_len);
	*i += arg_len;
	return (0);
}

static void	redirect_heredoc(char *cmd, size_t *i, t_redirect_fd *redirect,
	t_hd_node **heredoc_list)
{
	char		*redirect_start;
	size_t		redirect_len;

	redirect_start = cmd + *i;
	dprintf(2, "'%s'\n", redirect_start);
	redirect_len = 2;
	while (is_space(redirect_start[redirect_len]))
		++redirect_len;
	while (redirect_start[redirect_len]
		&& is_limiter_char(redirect_start[redirect_len]))
		++redirect_len;
	ft_memset(redirect_start, ' ', redirect_len);
	if (redirect->in > -1)
		secure_close(redirect->in);
	redirect->in = hd_pop(heredoc_list);
}

static int	redirect_out(char *cmd, size_t *i, t_redirect_fd *redirect,
	bool append)
{
	char	*arg_start;
	char	*file;
	size_t		arg_len;

	arg_start = cmd + *i;
	file = get_redirect_file(arg_start, &arg_len);
	if (!file)
		return (1);
	if (redirect->out > -1)
		secure_close(redirect->out);
	redirect->out = open(file, O_WRONLY | O_CREAT
			| (O_APPEND * append) | (O_TRUNC * !append), 0644);
	if (redirect->out == -1)
	{
		ft_dprintf(2, "open: %s: %s\n", file, strerror(errno));
		free(file);
		return (1);
	}
	free(file);
	ft_memset(arg_start, ' ', arg_len);
	*i += arg_len;
	return (0);
}

static int	stop_redirect(t_redirect_fd *redirect)
{
	if (redirect->in > -1)
		secure_close(redirect->in);
	if (redirect->out > -1)
		secure_close(redirect->out);
	return (1);
}

int	get_redirection(char *cmd, t_redirect_fd *redirect,
	t_hd_node **heredoc_list)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '"')
			skip_dquote(cmd, &i);
		else if (cmd[i] == '\'')
			skip_squote(cmd, &i);
		else if (cmd[i] == '<' && cmd[i + 1] == '<')
		{
			redirect_heredoc(cmd, &i, redirect, heredoc_list);
			printf("'%s'\n", cmd);
		}
		else if (cmd[i] == '<')
		{
			if (redirect_in(cmd, &i, redirect))
			return (stop_redirect(redirect));
		}
		else if (cmd[i] == '>')
		{
			if (redirect_out(cmd, &i, redirect, false))
			return (stop_redirect(redirect));
		}
		else if (cmd[i] == '>' && cmd[i + 1] == '>')
		{
			if (redirect_out(cmd, &i, redirect, true))
				return (stop_redirect(redirect));
		}
		else
			++i;
	}
	return (0);
}
