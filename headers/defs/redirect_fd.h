/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:13:21 by ebini             #+#    #+#             */
/*   Updated: 2025/06/06 00:05:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_FD_H
# define REDIRECT_FD_H

typedef struct s_redirect_fd
{
	int	in;
	int	out;
	int	err;
}			t_redirect_fd;

#endif
