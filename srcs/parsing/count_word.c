/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:02:47 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/10 09:26:43 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_word(char *str)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			continue ;
		++count;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			++i;
	}
	return (count);
}
