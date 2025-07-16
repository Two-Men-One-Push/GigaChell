/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:59:24 by CyberOneFR        #+#    #+#             */
/*   Updated: 2025/07/14 23:07:59 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLING_H
# define SIGNAL_HANDLING_H

void		handling_prompt_signal(void);
void		handling_execution_signal(void);
void		handling_child_signal(void);
void	sigint_handler(int code);
void	sigquit_handler(int code);

#endif