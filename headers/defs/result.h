/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:49:29 by ebini             #+#    #+#             */
/*   Updated: 2025/07/04 15:28:14 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_H
# define RESULT_H

enum e_result_type
{
	PROC_MAIN = 0,
	PROC_FORK,
	PROC_BUILTIN,
};

typedef struct s_pipe_result
{
	int		pid;
	short	status;
	char	type;
}			t_pipe_result;

#endif
