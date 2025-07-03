/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:22:13 by ebini             #+#    #+#             */
/*   Updated: 2025/06/30 19:41:16 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "defs/redirect_fd.h"

int	start_builtin(char **argv, t_redirect_fd *redirect, int *builtin_status);

int	ft_cd(int argc, char **argv, t_redirect_fd *redirect);
int	ft_exit(int argc, char **argv, t_redirect_fd *redirect);
int	ft_echo(int argc, char **argv, t_redirect_fd *redirect);
int	ft_pwd(int argc, char **argv, t_redirect_fd *redirect);
int	ft_env(int argc, char **argv, t_redirect_fd	*redirect);
int	ft_unset(int argc, char **argv, t_redirect_fd *redirect);
int	ft_export(int argc, char **argv, t_redirect_fd *redirect);

#endif
