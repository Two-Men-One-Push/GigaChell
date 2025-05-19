/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gigachell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/05/14 19:11:36 by ethebaul          #+#    #+#             */
/*   Updated: 2025/05/14 19:50:04 by ethebaul         ###   ########.fr       */
=======
/*   Created: 2025/05/08 15:25:45 by ebini             #+#    #+#             */
/*   Updated: 2025/05/15 19:48:42 by ethebaul         ###   ########.fr       */
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c
/*                                                                            */
/* ************************************************************************** */

#ifndef GIGACHELL_H
# define GIGACHELL_H

<<<<<<< HEAD
# include "lexer.h"
# include "syntax.h"

#endif
=======
# include <stdbool.h>

# include "heredoc_list_utils.h"
# include "syntax.h"

bool	parse_heredoc(char *cmd, t_hd_node **heredoc_list);

int		logic_exec(char *cmd, t_hd_node *heredoc_list);
int		pipe_exec(char *cmd, t_hd_node *heredoc_list);

#endif
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c
