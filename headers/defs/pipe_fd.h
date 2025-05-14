/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:55:28 by ebini             #+#    #+#             */
/*   Updated: 2025/05/12 00:56:56 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_FD_H
# define PIPE_FD_H

typedef struct s_pipe_fd
{
	int	in;
	int	out;
	int	next_in;
}			t_pipe_fd;

#endif