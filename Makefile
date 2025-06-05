#Folder------------------------------------------------------------------------#
SRCS_DIR			=	srcs/
BUILDIR				=	.build/
BUILDIR_DBG			=	.build_dbg/
HEADERS				=	headers/\
						headers/defs\
						headers/types\
						headers/parsing

#Sources-----------------------------------------------------------------------#
MAIN				=	main.c\
						utils/skip.c\
						utils/error.c\
						utils/secure_close.c\
						utils/get_heredoc_limiter.c\
						utils/expand.c\
						utils/str_extract.c\
						utils/unquote.c\
						utils/identifiers/is_space.c\
						utils/identifiers/is_redirection.c\
						utils/identifiers/is_logicalop.c\
						utils/identifiers/is_var_name.c\
						types/string/ftstring.c\
						here_doc/parse_heredoc.c\
						here_doc/tmp_fd.c\
						here_doc/heredoc.c\
						here_doc/heredoc_list/hd_pop.c\
						here_doc/heredoc_list/hd_new.c\
						here_doc/heredoc_list/hd_clear.c\
						here_doc/heredoc_list/hd_add_back.c\
						here_doc/heredoc_list/hd_add_front.c\
						print/swrite.c\
						builtin/echo.c\
						builtin/cd/cd.c\
						builtin/cd/cd_utils.c\
						parsing/skipto.c\
						parsing/syntax/syntax_operator/syntax_or.c\
						parsing/syntax/syntax_operator/syntax_close.c\
						parsing/syntax/syntax_operator/syntax_in.c\
						parsing/syntax/syntax_operator/syntax_append.c\
						parsing/syntax/syntax_operator/syntax_pipe.c\
						parsing/syntax/syntax_operator/syntax_squote.c\
						parsing/syntax/syntax_operator/syntax_and.c\
						parsing/syntax/syntax_operator/syntax_out.c\
						parsing/syntax/syntax_operator/syntax_dquote.c\
						parsing/syntax/syntax_operator/syntax_open.c\
						parsing/syntax/syntax_operator/syntax_heredoc.c\
						parsing/syntax/syntaxer.c\
						parsing/syntax/syntax_operator.c\
						logic_exec.c\
						alloc/smalloc.c

MAIN_DBG			=	main_dbg.c
SRCS_DBG			=	


#Objects and Dependancy files--------------------------------------------------#
DEPS				=	$(addprefix $(BUILDIR), $(MAIN:.c=.d) $(SRCS:.c=.d) $(MAIN_DBG:.c=.d) $(SRCS_DBG:.c=.d))

MAIN_OBJ			=	$(addprefix $(BUILDIR), $(MAIN:.c=.o))
OBJS				=	$(addprefix $(BUILDIR), $(SRCS:.c=.o))

MAIN_OBJ_DBG		=	$(addprefix $(BUILDIR_DBG), $(MAIN_DBG:.c=.o))
OBJS_DBG			=	$(addprefix $(BUILDIR_DBG), $(SRCS_DBG:.c=.o))

INCLUDE				=	$(addprefix -I, $(HEADERS))

#Name and Compilation----------------------------------------------------------#
NAME				=	GigaChell
DEBUG				=	debug

CC					=	clang
CFLAGS				=	-Wall -Wextra -Werror -O3 -g3 -march=native
CFLAGS_DBG			=	-Wall -Wextra -Werror -g3

LIBFT_FOLDER		=	libft
LIBFT_ARCHIVE		=	libft.a
LIBFT				=	$(LIBFT_FOLDER)/$(LIBFT_ARCHIVE)
LIBFT_INCLUDE_FLAGS	=	-I$(LIBFT_FOLDER)/include
LIBFT_FLAGS			=	-L$(LIBFT_FOLDER) -l$(shell echo $(LIBFT_ARCHIVE) | cut -c4- | rev | cut -c3- | rev)

#Rules-------------------------------------------------------------------------#
all: $(NAME)
	@echo Success

$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJS) $(MAIN_OBJ) $(LIBFT_FLAGS) -lreadline

$(DEBUG): $(MAIN_OBJ_DBG) $(OBJS) $(OBJS_DBG) $(LIBFT)
	$(CC) $(CFLAGS_DBG) $(INCLUDE) -o $@ $(OBJS) $(OBJS_DBG) $(MAIN_OBJ_DBG) $(LIBFT_FLAGS) -lreadline

$(BUILDIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_INCLUDE_FLAGS) -MD -MP -o $@ -c $<

$(BUILDIR_DBG)%.o: $(SRCS_DIR)%.c | $(BUILDIR_DBG)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_DBG) $(INCLUDE) $(LIBFT_INCLUDE_FLAGS) -MD -MP -o $@ -c $<

$(LIBFT): FORCE
	make -C $(LIBFT_FOLDER)

-include $(DEPS)

clean:
	rm -rf $(BUILDIR) $(BUILDIR_DBG)
	make -C $(LIBFT_FOLDER) clean

fclean: clean
	rm -f $(NAME) $(DEBUG)
	make -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY : all clean fclean re FORCE