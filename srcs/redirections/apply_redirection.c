/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:57:08 by ebini             #+#    #+#             */
/*   Updated: 2025/06/02 19:23:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>

#include "defs/hd_node.h"
#include "defs/redirect_fd.h"
#include "utils.h"
#include "libft.h"

int	redirect_in(char *cmd, size_t *i, t_redirect_fd *redirect)
{
	const char	*arg_start = cmd + *i;
	const char	*file = get_redirect_file(arg_start);
	size_t		arg_len;

	if (!file)	
		return (1);
	if (redirect->in > -1)
		secure_close(redirect->in);
	redirect->in = open(file, O_RDONLY);
	free(file);
	if (redirect->in = -1)	
		return (1);
	arg_len = 1;
	while (is_space(arg_start[arg_len]))
		++arg_len;
	while (!is_space(arg_start[arg_len]))
		++arg_len;
	ft_memset(arg_start, ' ', arg_len);
	*i += arg_len;
}

int	redirect_heredoc(char *cmd, size_t *i, t_redirect_fd *redirect,
	t_hd_node *heredoc_list)
{

}

int	redirect_out_trunc(char *cmd, size_t *i, t_redirect_fd *redirect,
	bool append)
{
	const char	*arg_start = cmd + *i;
	const char	*file = get_redirect_file(arg_start);
	size_t		arg_len;

	if (!file)	
		return (1);
	if (redirect->out > -1)
		secure_close(redirect->in);
	redirect->out = open(file,
		O_WRONLY | O_CREAT | (O_APPEND * append) | (O_TRUNC * !append), 0644);
	free(file);
	if (redirect->out = -1)
		return (1);
	arg_len = 1 + append;
	while (is_space(arg_start[arg_len]))
		++arg_len;
	while (!is_space(arg_start[arg_len]))
		++arg_len;
	ft_memset(arg_start, ' ', arg_len);
	*i += arg_len;
}

int	stop_redirect(t_redirect_fd *redirect)
{
	if (redirect->in > -1)
		secure_close(redirect->in);
	if (redirect->out > -1)
		secure_close(redirect->in);
	return(1);
}

int	apply_redirection(char *cmd, t_redirect_fd *redirect,
	t_hd_node *heredoc_list)
{
	size_t	i;

	i = -1;
	while (cmd[i])
	{
		if (cmd[i] == '"')
			skip_dquote(cmd, &i);
		else if (cmd[i] == '\'')
			skip_squote(cmd, &i);
		else if (cmd[i] == '<')
			if (redirect_in(cmd, &i, redirect))
				return (stop_redirect(redirect));
		else if (cmd[i] == '<' && cmd[i + 1] == '<')
			if (redirect_heredoc())
				return (stop_redirect(redirect));
		else if (cmd[i] == '>')
			if (redirect_out())
				return (stop_redirect(redirect));
		else if (cmd[i] == '>' && cmd[i + 1] == '>')
			if (redirect_out())
				return (stop_redirect(redirect));
		else
			++i;
	}
	return (0);
}
