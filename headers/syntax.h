/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:46:13 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/19 10:56:58 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

int	check_syntax(char *cmd);
int	serror(char *str);
int	syntax_or(char **line, int *cmd, int *op);
int	syntax_and(char **line, int *cmd, int *op);
int	syntax_pclose(int *cmd, int *depth);
int	syntax_popen(int *cmd, int *depth);
int	syntax_action(char **line, int *cmd, int *op, int *depth);

#endif