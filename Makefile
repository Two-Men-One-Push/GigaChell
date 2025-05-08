# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 17:15:05 by ethebaul          #+#    #+#              #
#    Updated: 2025/05/08 17:11:33 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILDIR		=	./build/
BUILDIR_DBG	=	./build_dbg/
HEADERS		=	./headers/

VPATH		=	./srcs/

SRCS		=	main.c\
				ft_clearenv.c\
				ft_getenv.c\
				ft_getenvp.c\
				ft_initenv.c\
				ft_setenv.c\
				ft_unsetenv.c\
				env_clear.c\
				env_get.c\
				env_handle.c\
				env_init.c\
				env_set.c\
				env_to_envp.c\
				env_unset.c\
				realloc_env.c\
				

SRCS_DBG	=	./srcs_dbg/debug.c

DEPS		=	$(addprefix $(BUILDIR), $(SRCS:.c=.d))
OBJS		=	$(addprefix $(BUILDIR), $(SRCS:.c=.o))
DEPS_DBG	=	$(addprefix $(BUILDIR_DBG), $(SRCS:.c=.d))
OBJS_DBG	=	$(addprefix $(BUILDIR_DBG), $(SRCS:.c=.o))

NAME		=	libc.a
DEBUG		=	debug

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3 -march=native -I$(HEADERS)
CFLAGS_DBG	=	-Wall -Wextra -Werror -g3 -I$(HEADERS)

all: $(NAME)

$(NAME): $(OBJS) Makefile
	ar rcs $@ $(OBJS)

$(DEBUG): $(OBJS_DBG) $(SRCS_DBG) Makefile
	$(CC) $(CFLAGS_DBG) -MD -MP -MF $(BUILDIR_DBG)$@.d -o $@ $(OBJS_DBG) $(SRCS_DBG)

$(BUILDIR)%.o: %.c | $(BUILDIR)
	$(CC) $(CFLAGS) -MD -MP -o $@ -c $<

$(BUILDIR_DBG)%.o: %.c | $(BUILDIR_DBG)
	$(CC) $(CFLAGS_DBG) -MD -MP -o $@ -c $<

$(BUILDIR):
	mkdir -p $@

$(BUILDIR_DBG):
	mkdir -p $@

-include $(DEPS) $(DEPS_DBG)

clean:
	rm -rf $(BUILDIR) $(BUILDIR_DBG)

fclean: clean
	rm -f $(NAME) $(DEBUG)

re: fclean all

.PHONY : all clean fclean re