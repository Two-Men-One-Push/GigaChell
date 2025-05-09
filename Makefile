# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 17:15:05 by ethebaul          #+#    #+#              #
#    Updated: 2025/05/09 15:27:53 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILDIR		=	./build/
HEADERS		=	./headers/

VPATH		=	$(shell find ./srcs/ -type d)

SRCS		=	main.c
				
DEPS		=	$(addprefix $(BUILDIR), $(SRCS:.c=.d))
OBJS		=	$(addprefix $(BUILDIR), $(SRCS:.c=.o))

NAME		=	GigaChell

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3 -march=native -I$(HEADERS)

all: $(NAME)
	@echo Success

$(NAME): $(OBJS) $(SRCS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BUILDIR)%.o: %.c | $(BUILDIR)
	$(CC) $(CFLAGS) -MD -MP -o $@ -c $<

$(BUILDIR):
	mkdir -p $@

-include $(DEPS)

clean:
	rm -rf $(BUILDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re