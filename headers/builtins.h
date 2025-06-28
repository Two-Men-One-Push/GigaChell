/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:22:13 by ebini             #+#    #+#             */
/*   Updated: 2025/06/28 06:44:11 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "defs/redirect_fd.h"

int	start_builtin(char **argv, t_redirect_fd *redirect, int *builtin_status);

int	ftcd(int argc, char **argv, t_redirect_fd *redirect);
int	ftexit(int argc, char **argv, t_redirect_fd *redirect);

#endif
