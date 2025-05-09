# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 17:15:05 by ethebaul          #+#    #+#              #
#    Updated: 2025/05/09 16:15:29 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILDIR		=	./build/
BUILDIR_DBG	=	./build_dbg/
HEADERS		=	./headers/

VPATH		=	$(shell find ./srcs/ -type d):$(shell find ./srcs_dbg/ -type d)

SRCS		=	main.c
				
SRCS_DBG	=	main_dbg.c

DEPS		=	$(addprefix $(BUILDIR), $(SRCS:.c=.d))
OBJS		=	$(addprefix $(BUILDIR), $(SRCS:.c=.o))
DEPS_DBG	=	$(addprefix $(BUILDIR_DBG), $(SRCS:.c=.d))
OBJS_DBG	=	$(addprefix $(BUILDIR_DBG), $(SRCS:.c=.o))

NAME		=	GigaChell
DEBUG		=	debug

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3 -march=native -I$(HEADERS)
CFLAGS_DBG	=	-Wall -Wextra -Werror -g3 -I$(HEADERS)

all: $(NAME)
	@echo Success

$(NAME): $(OBJS) $(SRCS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(DEBUG): $(OBJS) $(SRCS) $(OBJS_DBG) $(SRCS_DBG) Makefile
	$(CC) $(CFLAGS_DBG) -o $@ $(OBJS) $(OBJS_DBG)

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