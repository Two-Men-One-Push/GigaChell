/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:59:24 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/17 01:04:31 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLING_H
# define SIGNAL_HANDLING_H

void	handling_prompt_signal(void);
void	handling_execution_signal(void);
void	handling_child_signal(void);
void	handling_heredoc_signal(void);
void	sigint_handler(int code);
void	sigquit_handler(int code);
void	hd_sigint_handler(int code);
int		signal_event_hook(void);

#endif