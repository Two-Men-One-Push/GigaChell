/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:22:13 by ebini             #+#    #+#             */
/*   Updated: 2025/06/27 22:10:19 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "defs/redirect_fd.h"

int	start_builtin(char **cmd, t_redirect_fd *redirect);

int	ftcd(int argc, char **argv, t_redirect_fd *redirect);
int	ftexit(int argc, char **argv, t_redirect_fd *redirect);

#endif
