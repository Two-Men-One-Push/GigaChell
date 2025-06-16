HEADERS =	\
	-I./headers/\
	-I./headers/defs\
	-I./headers/parsing\
	-I./headers/types\
	-I./libft/include/

SRCS =	\
	./srcs/builtin/cd/cd_utils.c\
	./srcs/builtin/cd/cd.c\
	./srcs/builtin/env.c\
	./srcs/builtin/pwd.c\
	./srcs/builtin/echo.c\
	./srcs/here_doc/heredoc_list/hd_add_back.c\
	./srcs/here_doc/heredoc_list/hd_add_front.c\
	./srcs/here_doc/heredoc_list/hd_clear.c\
	./srcs/here_doc/heredoc_list/hd_new.c\
	./srcs/here_doc/heredoc_list/hd_pop.c\
	./srcs/here_doc/parse_heredoc.c\
	./srcs/here_doc/heredoc.c\
	./srcs/here_doc/tmp_fd.c\
	./srcs/utils/error.c\
	./srcs/utils/identifiers/is_logicalop.c\
	./srcs/utils/identifiers/is_redirection.c\
	./srcs/utils/identifiers/is_space.c\
	./srcs/utils/identifiers/is_var_name.c\
	./srcs/utils/skip.c\
	./srcs/utils/str_extract.c\
	./srcs/utils/unquote.c\
	./srcs/utils/get_heredoc_limiter.c\
	./srcs/utils/secure_close.c\
	./srcs/alloc/smalloc.c\
	./srcs/parsing/syntax/syntax_operator/syntax_and.c\
	./srcs/parsing/syntax/syntax_operator/syntax_append.c\
	./srcs/parsing/syntax/syntax_operator/syntax_close.c\
	./srcs/parsing/syntax/syntax_operator/syntax_dquote.c\
	./srcs/parsing/syntax/syntax_operator/syntax_heredoc.c\
	./srcs/parsing/syntax/syntax_operator/syntax_in.c\
	./srcs/parsing/syntax/syntax_operator/syntax_open.c\
	./srcs/parsing/syntax/syntax_operator/syntax_or.c\
	./srcs/parsing/syntax/syntax_operator/syntax_out.c\
	./srcs/parsing/syntax/syntax_operator/syntax_pipe.c\
	./srcs/parsing/syntax/syntax_operator/syntax_squote.c\
	./srcs/parsing/syntax/syntax_operator.c\
	./srcs/parsing/syntax/syntaxer.c\
	./srcs/parsing/skipto.c\
	./srcs/parsing/expand/expand.c\
	./srcs/types/string/ftstring.c\
	./srcs/types/chain/chain_init.c\
	./srcs/types/chain/chain_append.c\
	./srcs/types/chain/chain_link/chain_link_init.c\
	./srcs/types/chain/chain_link/chain_link_new.c\
	./srcs/types/chain/chain_free.c\
	./srcs/logic_exec.c\
	./srcs/main.c\
	./srcs/pipe_exec.c

OBJS =	\
	./build/cd_utils.o\
	./build/cd.o\
	./build/env.o\
	./build/pwd.o\
	./build/echo.o\
	./build/hd_add_back.o\
	./build/hd_add_front.o\
	./build/hd_clear.o\
	./build/hd_new.o\
	./build/hd_pop.o\
	./build/parse_heredoc.o\
	./build/heredoc.o\
	./build/tmp_fd.o\
	./build/error.o\
	./build/is_logicalop.o\
	./build/is_redirection.o\
	./build/is_space.o\
	./build/is_var_name.o\
	./build/skip.o\
	./build/str_extract.o\
	./build/unquote.o\
	./build/get_heredoc_limiter.o\
	./build/secure_close.o\
	./build/smalloc.o\
	./build/syntax_and.o\
	./build/syntax_append.o\
	./build/syntax_close.o\
	./build/syntax_dquote.o\
	./build/syntax_heredoc.o\
	./build/syntax_in.o\
	./build/syntax_open.o\
	./build/syntax_or.o\
	./build/syntax_out.o\
	./build/syntax_pipe.o\
	./build/syntax_squote.o\
	./build/syntax_operator.o\
	./build/syntaxer.o\
	./build/skipto.o\
	./build/expand.o\
	./build/ftstring.o\
	./build/chain_init.o\
	./build/chain_append.o\
	./build/chain_link_init.o\
	./build/chain_link_new.o\
	./build/chain_free.o\
	./build/logic_exec.o\
	./build/main.o\
	./build/pipe_exec.o

DEPS =	\
	./build/cd_utils.d\
	./build/cd.d\
	./build/env.d\
	./build/pwd.d\
	./build/echo.d\
	./build/hd_add_back.d\
	./build/hd_add_front.d\
	./build/hd_clear.d\
	./build/hd_new.d\
	./build/hd_pop.d\
	./build/parse_heredoc.d\
	./build/heredoc.d\
	./build/tmp_fd.d\
	./build/error.d\
	./build/is_logicalop.d\
	./build/is_redirection.d\
	./build/is_space.d\
	./build/is_var_name.d\
	./build/skip.d\
	./build/str_extract.d\
	./build/unquote.d\
	./build/get_heredoc_limiter.d\
	./build/secure_close.d\
	./build/smalloc.d\
	./build/syntax_and.d\
	./build/syntax_append.d\
	./build/syntax_close.d\
	./build/syntax_dquote.d\
	./build/syntax_heredoc.d\
	./build/syntax_in.d\
	./build/syntax_open.d\
	./build/syntax_or.d\
	./build/syntax_out.d\
	./build/syntax_pipe.d\
	./build/syntax_squote.d\
	./build/syntax_operator.d\
	./build/syntaxer.d\
	./build/skipto.d\
	./build/expand.d\
	./build/ftstring.d\
	./build/chain_init.d\
	./build/chain_append.d\
	./build/chain_link_init.d\
	./build/chain_link_new.d\
	./build/chain_free.d\
	./build/logic_exec.d\
	./build/main.d\
	./build/pipe_exec.d

$(BUILD_DIR):
	@mkdir -p $@
	@echo -e
	@echo -e $(FGREEN)created $(BUILD_DIR)$(RESET)

./build/cd_utils.o: ./srcs/builtin/cd/cd_utils.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/cd.o: ./srcs/builtin/cd/cd.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/env.o: ./srcs/builtin/env.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/pwd.o: ./srcs/builtin/pwd.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/echo.o: ./srcs/builtin/echo.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/hd_add_back.o: ./srcs/here_doc/heredoc_list/hd_add_back.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/hd_add_front.o: ./srcs/here_doc/heredoc_list/hd_add_front.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/hd_clear.o: ./srcs/here_doc/heredoc_list/hd_clear.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/hd_new.o: ./srcs/here_doc/heredoc_list/hd_new.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/hd_pop.o: ./srcs/here_doc/heredoc_list/hd_pop.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/parse_heredoc.o: ./srcs/here_doc/parse_heredoc.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/heredoc.o: ./srcs/here_doc/heredoc.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/tmp_fd.o: ./srcs/here_doc/tmp_fd.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/error.o: ./srcs/utils/error.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/is_logicalop.o: ./srcs/utils/identifiers/is_logicalop.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/is_redirection.o: ./srcs/utils/identifiers/is_redirection.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/is_space.o: ./srcs/utils/identifiers/is_space.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/is_var_name.o: ./srcs/utils/identifiers/is_var_name.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/skip.o: ./srcs/utils/skip.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/str_extract.o: ./srcs/utils/str_extract.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/unquote.o: ./srcs/utils/unquote.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/get_heredoc_limiter.o: ./srcs/utils/get_heredoc_limiter.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/secure_close.o: ./srcs/utils/secure_close.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/smalloc.o: ./srcs/alloc/smalloc.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_and.o: ./srcs/parsing/syntax/syntax_operator/syntax_and.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_append.o: ./srcs/parsing/syntax/syntax_operator/syntax_append.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_close.o: ./srcs/parsing/syntax/syntax_operator/syntax_close.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_dquote.o: ./srcs/parsing/syntax/syntax_operator/syntax_dquote.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_heredoc.o: ./srcs/parsing/syntax/syntax_operator/syntax_heredoc.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_in.o: ./srcs/parsing/syntax/syntax_operator/syntax_in.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_open.o: ./srcs/parsing/syntax/syntax_operator/syntax_open.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_or.o: ./srcs/parsing/syntax/syntax_operator/syntax_or.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_out.o: ./srcs/parsing/syntax/syntax_operator/syntax_out.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_pipe.o: ./srcs/parsing/syntax/syntax_operator/syntax_pipe.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_squote.o: ./srcs/parsing/syntax/syntax_operator/syntax_squote.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntax_operator.o: ./srcs/parsing/syntax/syntax_operator.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/syntaxer.o: ./srcs/parsing/syntax/syntaxer.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/skipto.o: ./srcs/parsing/skipto.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/expand.o: ./srcs/parsing/expand/expand.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/ftstring.o: ./srcs/types/string/ftstring.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/chain_init.o: ./srcs/types/chain/chain_init.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/chain_append.o: ./srcs/types/chain/chain_append.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/chain_link_init.o: ./srcs/types/chain/chain_link/chain_link_init.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/chain_link_new.o: ./srcs/types/chain/chain_link/chain_link_new.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/chain_free.o: ./srcs/types/chain/chain_free.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/logic_exec.o: ./srcs/logic_exec.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/main.o: ./srcs/main.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)

./build/pipe_exec.o: ./srcs/pipe_exec.c | $(BUILD_DIR)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e - $(FGREEN)compiling $<$(RESET)
