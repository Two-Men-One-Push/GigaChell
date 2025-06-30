/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:49:29 by ebini             #+#    #+#             */
/*   Updated: 2025/06/28 02:51:05 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_H
# define RESULT_H

enum e_result_type
{
	RT_MAIN = 0,
	RT_FORK,
	RT_BUILTIN,
};

typedef struct s_pipe_result
{
	int		pid;
	short	status;
	char	type;
}			t_pipe_result;

#endif
