/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:12:50 by ebini             #+#    #+#             */
/*   Updated: 2025/07/17 02:37:45 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"
#include "identifier.h"
#include "libft.h"
#include "env.h"

int	add_env_var(char *str, size_t *i, char **filename)
{
	char	*new_filename;

	if (!is_var_start(str[++*i]))
	{
		new_filename = ft_strjoin(*filename, "$");
		free(*filename);
		if (!new_filename)
			return (1);
		*filename = new_filename;
		return (0);
	}
	new_filename = ft_strjoin(*filename, ft_getenv(str + *i));
	free(*filename);
	if (!new_filename)
		return (1);
	*filename = new_filename;
	*i += 2;
	while (is_var_char(str[*i]))
		++*i;
	return (0);
}

int	add_neutral(char *str, size_t *i, char **filename, int handle_quote)
{
	size_t	arg_len;
	size_t	old_len;
	char	*new_filename;

	arg_len = 0;
	while (str[*i + arg_len] && str[*i + arg_len] != '$'
		&& (!handle_quote || (str[*i + arg_len] != '"'
				&& (handle_quote < 2 || str[*i + arg_len] != '\''))))
		++arg_len;
	old_len = ft_strlen(*filename);
	new_filename = malloc(old_len + arg_len + 1);
	if (!new_filename)
	{
		free(*filename);
		return (1);
	}
	ft_strcpy(new_filename, *filename);
	ft_strncpy(new_filename + old_len, str + *i, arg_len);
	new_filename[old_len + arg_len] = '\0';
	free(*filename);
	*filename = new_filename;
	*i += arg_len;
	return (0);
}

int	add_squote(char *str, size_t *i, char **filename)
{
	size_t	arg_len;
	size_t	old_len;
	char	*new_filename;

	++*i;
	arg_len = 0;
	while (str[*i + arg_len] != '\'')
		++arg_len;
	old_len = ft_strlen(*filename);
	new_filename = malloc(old_len + arg_len + 1);
	if (!new_filename)
	{
		free(*filename);
		return (1);
	}
	*new_filename = '\0';
	ft_strcpy(new_filename, *filename);
	ft_strncpy(new_filename + old_len, str + *i, arg_len);
	new_filename[old_len + arg_len] = '\0';
	free(*filename);
	*filename = new_filename;
	*i += arg_len + 1;
	return (0);
}

int	add_dquote(char *str, size_t *i, char **filename)
{
	++*i;
	while (str[*i] != '"')
	{
		if (str[*i] == '$' && add_env_var(str, i, filename))
			return (1);
		else if (str[*i] != '"' && add_neutral(str, i, filename, 1))
			return (1);
	}
	++*i;
	return (0);
}

char	*parse_arg(char *str, bool handle_quote)
{
	size_t	i;
	char	*filename;

	filename = ft_calloc(1, sizeof(char));
	if (!filename)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (handle_quote && str[i] == '\'' && add_squote(str, &i, &filename))
			return (NULL);
		else if (handle_quote && str[i] == '"' && add_dquote(str, &i, &filename))
			return (NULL);
		else if (str[i] == '$' && add_env_var(str, &i, &filename))
			return (NULL);
		else if (str[i] && add_neutral(str, &i, &filename, handle_quote * 2))
			return (NULL);
	}
	return (filename);
}
