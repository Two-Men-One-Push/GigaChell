/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandling.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:59:24 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/11 22:17:59 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGHANDLING_H
# define SIGHANDLING_H

void	sigint_handler(int code);
int		handling_prompt_signal(void);
int		handling_execution_signal(void);

#endif