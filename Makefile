# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 17:15:05 by ethebaul          #+#    #+#              #
#    Updated: 2025/05/12 01:15:41 by ebini            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BUILDIR			=	./.build/
BUILDIR_DBG		=	./.build_dbg/
HEADERS			=	./headers/

VPATH			=	$(shell find ./srcs/ -type d):$(shell find ./srcs_dbg/ -type d)

MAIN			=	main.c
SRCS			=	error.c \
					ft_strlen.c

MAIN_DBG		=	main_dbg.c
SRCS_DBG		=	

DEPS			=	$(addprefix $(BUILDIR), $(SRCS:.c=.d))
OBJS			=	$(addprefix $(BUILDIR), $(SRCS:.c=.o))
MAIN_OBJ		=	$(addprefix $(BUILDIR), $(MAIN:.c=.o))
DEPS_DBG		=	$(addprefix $(BUILDIR_DBG), $(SRCS_DBG:.c=.d))
OBJS_DBG		=	$(addprefix $(BUILDIR_DBG), $(SRCS_DBG:.c=.o))
MAIN_OBJ_DBG	=	$(addprefix $(BUILDIR_DBG), $(MAIN_DBG:.c=.o))

NAME			=	GigaChell
DEBUG			=	debug

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -O3 -march=native -I$(HEADERS)
CFLAGS_DBG		=	-Wall -Wextra -Werror -g3 -I$(HEADERS)

all: $(NAME)
	@echo Success

$(NAME): $(OBJS) $(MAIN_OBJ) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MAIN_OBJ)

$(DEBUG): $(OBJS) $(OBJS_DBG) $(MAIN_OBJ_DBG) Makefile
	$(CC) $(CFLAGS_DBG) -o $@ $(OBJS) $(OBJS_DBG) $(MAIN_OBJ_DBG)

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