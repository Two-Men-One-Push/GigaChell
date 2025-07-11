/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandling.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:59:24 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/11 21:59:59 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGHANDLING_H
# define SIGHANDLING_H

void	sigint_handler(int code);
int		set_signal(void);

#endif