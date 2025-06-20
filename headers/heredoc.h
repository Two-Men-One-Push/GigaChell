/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:29 by ebini             #+#    #+#             */
/*   Updated: 2025/05/13 21:48:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "heredoc_list_utils.h"

# define RANDOM_FILE "/dev/urandom"
# define GIGACHELL_TMP_PATH "/tmp/gigachell_heredoc_"
# define RANDOM_FILE_TRY_MAX 16

/**
 * @brief Generate a temporary file and write the STDIN in it.
 * @param limiter The limiter indicating EOF
 * @param path The path that will be set to unsync the temporary file
 * @warning The memory newly pointed by *path should be released using free().
 * @return An fd of the new created file with O_RDONLY flag or -1 is an error
 * occured.
 */
int	create_here_doc(char *limiter);

#endif
