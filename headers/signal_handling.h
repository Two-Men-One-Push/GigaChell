/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CyberOneFR <noyoudont@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:59:24 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/12 10:15:14 by CyberOneFR       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLING_H
# define SIGNAL_HANDLING_H

int		handling_prompt_signal(void);
int		handling_execution_signal(void);
void	sigint_handler(int code);
void	sigint_ignore(int code);
void	sigquit_handler(int code);
void	sigquit_ignore(int code);

#endif