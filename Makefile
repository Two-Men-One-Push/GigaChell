<<<<<<< HEAD
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 17:15:05 by ethebaul          #+#    #+#              #
#    Updated: 2025/05/14 19:44:01 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILDIR		=	./build/
BUILDIR_DBG	=	./build_dbg/
HEADERS		=	$(shell find ./headers/ -type d)

VPATH		=	$(shell find ./srcs/ -type d):$(shell find ./srcs_dbg/ -type d)

SRCS		=	$(notdir $(shell find ./srcs/ -type f -name "*.c"))
				
SRCS_DBG	=	main_dbg.c
=======

#Folder------------------------------------------------------------------------#
BUILDIR				=	./.build/
BUILDIR_DBG			=	./.build_dbg/
HEADERS				=	./headers/

VPATH				=	$(shell find ./srcs/ -type d):$(shell find ./srcs_dbg/ -type d)

#Sources-----------------------------------------------------------------------#
MAIN				=	main.c
SRCS				=	logic_exec.c \
						heredoc.c \
						tmp_fd.c \
						hd_new.c \
						hd_add_front.c \
						hd_add_back.c \
						hd_pop.c \
						hd_clear.c \
						is_logicalop.c \
						is_redirection.c \
						is_space.c \
						is_var_name.c \
						parse_heredoc.c \
						get_heredoc_limiter.c \
						str_extract.c \
						unquote.c \
						skip.c \
						cd.c \
						cd_utils.c \
						secure_close.c \
						error.c \
						check_syntax.c
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c

MAIN_DBG			=	main_dbg.c
SRCS_DBG			=	

#Objects and Dependancy files--------------------------------------------------#
DEPS				=	$(addprefix $(BUILDIR), $(MAIN:.c=.d) $(SRCS:.c=.d) $(MAIN_DBG:.c=.d) $(SRCS_DBG:.c=.d))

<<<<<<< HEAD
CC			=	cc
LIBS		=	-lreadline -lncurses
CFLAGS		=	-Wall -Wextra -Werror -O3 -march=native $(addprefix -I, $(HEADERS))
CFLAGS_DBG	=	-Wall -Wextra -Werror -g3 $(addprefix -I, $(HEADERS))
=======
MAIN_OBJ			=	$(addprefix $(BUILDIR), $(MAIN:.c=.o))
OBJS				=	$(addprefix $(BUILDIR), $(SRCS:.c=.o))
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c

MAIN_OBJ_DBG		=	$(addprefix $(BUILDIR_DBG), $(MAIN_DBG:.c=.o))
OBJS_DBG			=	$(addprefix $(BUILDIR_DBG), $(SRCS_DBG:.c=.o))

#Name and Compilation----------------------------------------------------------#
NAME				=	GigaChell
DEBUG				=	debug

CC					=	clang
CFLAGS				=	-Wall -Wextra -Werror -O3 -g3 -march=native -I$(HEADERS)
CFLAGS_DBG			=	-Wall -Wextra -Werror -g3 -I$(HEADERS)

LIBFT_FOLDER		=	libft
LIBFT_ARCHIVE		=	libft.a
LIBFT				=	$(LIBFT_FOLDER)/$(LIBFT_ARCHIVE)
LIBFT_INCLUDE_FLAGS	=	-I$(LIBFT_FOLDER)/include
LIBFT_FLAGS			=	-L$(LIBFT_FOLDER) -l$(shell echo $(LIBFT_ARCHIVE) | cut -c4- | rev | cut -c3- | rev)

#Rules-------------------------------------------------------------------------#
all: $(NAME)
	@echo Success

<<<<<<< HEAD
$(NAME): $(OBJS) $(SRCS) Makefile
	$(CC) $(CFLAGS) $(LIBS) -o $@ $(OBJS)

$(DEBUG): $(OBJS) $(SRCS) $(OBJS_DBG) $(SRCS_DBG) Makefile
	$(CC) $(CFLAGS_DBG) $(LIBS) -o $@ $(OBJS) $(OBJS_DBG)
=======
$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MAIN_OBJ) $(LIBFT_FLAGS) -lreadline

$(DEBUG): $(MAIN_OBJ_DBG) $(OBJS) $(OBJS_DBG) $(LIBFT)
	$(CC) $(CFLAGS_DBG) -o $@ $(OBJS) $(OBJS_DBG) $(MAIN_OBJ_DBG) $(LIBFT_FLAGS) -lreadline
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c

$(BUILDIR)%.o: %.c | $(BUILDIR)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE_FLAGS) -MD -MP -o $@ -c $<

$(BUILDIR_DBG)%.o: %.c | $(BUILDIR_DBG)
	$(CC) $(CFLAGS_DBG) $(LIBFT_INCLUDE_FLAGS) -MD -MP -o $@ -c $<

$(BUILDIR):
	@mkdir -p $@

$(BUILDIR_DBG):
	@mkdir -p $@

$(LIBFT): FORCE
	make -C $(LIBFT_FOLDER)

-include $(DEPS)

clean:
<<<<<<< HEAD
	@rm -rf $(BUILDIR) $(BUILDIR_DBG)

fclean: clean
	@rm -f $(NAME) $(DEBUG)
=======
	rm -rf $(BUILDIR) $(BUILDIR_DBG)
	make -C $(LIBFT_FOLDER) clean

fclean: clean
	rm -f $(NAME) $(DEBUG)
	make -C $(LIBFT_FOLDER) fclean
>>>>>>> 7ab9a6bfe1eb3cebb5ca95588bcceb6d74a3ec0c

re: fclean all

.PHONY : all clean fclean re FORCE