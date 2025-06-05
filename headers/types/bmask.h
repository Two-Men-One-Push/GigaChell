/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmask.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:26:59 by ethebaul          #+#    #+#             */
/*   Updated: 2025/06/05 17:47:02 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMASK_H
# define BMASK_H

struct s_bmask
{
	unsigned char	b1 : 1;
	unsigned char	b2 : 1;
	unsigned char	b3 : 1;
	unsigned char	b4 : 1;
	unsigned char	b5 : 1;
	unsigned char	b6 : 1;
	unsigned char	b7 : 1;
	unsigned char	b8 : 1;
};

typedef union u_bmask
{
	struct s_bmask	mask;
	unsigned char	value;
}	t_bmask;

#endif