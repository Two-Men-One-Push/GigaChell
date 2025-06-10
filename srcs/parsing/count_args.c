/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:02:47 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/10 09:48:09 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstring.h"
#include "libft.h"

int	count_args(char *str)
{
	int		count;
	size_t	i;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			continue ;
		if (str[i] == '\"')
			skipto(ftstring(&str[i], ft_strlen(&str[i])), &i, '\"');
		if (str[i] == '\'')
			skipto(ftstring(&str[i], ft_strlen(&str[i])), &i, '\'');
		++count;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			++i;
	}
	return (count);
}
