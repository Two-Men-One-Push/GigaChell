/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:05:16 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/14 19:56:13 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include <unistd.h>
# include "t_size.h"
# include "t_stref.h"

int	check_syntax(char *line);
int	syntax_error(t_stref stref);

#endif