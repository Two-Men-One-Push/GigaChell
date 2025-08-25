# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 14:31:25 by ethebaul          #+#    #+#              #
#    Updated: 2025/08/25 21:54:22 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILD_DIR			=	./build/
HEADERS_DIR			=	./headers/ ./libft/include/
SRCS_DIR			=	./srcs/

MKCONFIGURE			=	./configure.mk
MKGENERATED			=	./generated.mk
MKCOLOR				=	./color.mk

LIBFT_DIR			=	./libft/
LIBFT_ARCHIVE		=	$(LIBFT_DIR)libft.a

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -g3 $(CMD_CFLAGS)
LDLIBS				=	-lreadline -L$(LIBFT_DIR) -l$(patsubst lib%,%,$(notdir $(basename $(LIBFT_ARCHIVE))))

NAME				=	minishell

all: $(NAME)
	@echo -e $(GREEN)Successfully Built $(NAME)$(RESET)

-include $(MKCONFIGURE) $(MKGENERATED)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ $(OBJS) $(LDLIBS)
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

$(LIBFT_ARCHIVE): FORCE
	@make --no-print-dir -C $(LIBFT_DIR) dev

normcheck:
	@echo -e -n $(RED)
	@norminette | grep "Error:" || echo $(GREEN)Norminette: OK
	@echo -e -n $(RESET)

clangd:
	@rm -f compile_commands.json
	@echo $(CC) $(CFLAGS) $(HEADERS) -o $(NAME) $(SRCS) $(LDLIBS) | compiledb

clean:
	@make --no-print-dir -C $(LIBFT_DIR) clean
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make --no-print-dir -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean
	$(MAKE) all

-include $(DEPS)

.PHONY : all clean fclean re clangd normcheck configure FORCE
