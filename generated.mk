HEADERS =	\
	-I./headers/\
	-I./headers/defs\
	-I./headers/parsing\
	-I./headers/types\
	-I./libft/include/

SRCS =	\
	./srcs/alloc/smalloc.c\
	./srcs/builtin/cd/cd.c\
	./srcs/builtin/cd/cd_utils.c\
	./srcs/builtin/echo.c\
	./srcs/builtin/env.c\
	./srcs/builtin/pwd.c\
	./srcs/builtin/start_builtin.c\
	./srcs/handle_piped_cmd.c\
	./srcs/here_doc/heredoc.c\
	./srcs/here_doc/heredoc_list/hd_add_back.c\
	./srcs/here_doc/heredoc_list/hd_add_front.c\
	./srcs/here_doc/heredoc_list/hd_clear.c\
	./srcs/here_doc/heredoc_list/hd_move.c\
	./srcs/here_doc/heredoc_list/hd_new.c\
	./srcs/here_doc/heredoc_list/hd_pop.c\
	./srcs/here_doc/parse_heredoc.c\
	./srcs/here_doc/tmp_fd.c\
	./srcs/logic_exec.c\
	./srcs/parsing/expand/expand.c\
	./srcs/parsing/expand/expand_core.c\
	./srcs/parsing/skipto.c\
	./srcs/parsing/syntax/syntax_operator.c\
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
	./srcs/parsing/syntax/syntaxer.c\
	./srcs/pipe_exec.c\
	./srcs/redirections/apply_redirection.c\
	./srcs/redirections/get_redirect_file.c\
	./srcs/redirections/get_redirection.c\
	./srcs/start_splitted_cmd.c\
	./srcs/subshell_exec.c\
	./srcs/types/chain/chain_append.c\
	./srcs/types/chain/chain_free.c\
	./srcs/types/chain/chain_init.c\
	./srcs/types/chain/chain_link/chain_link_init.c\
	./srcs/types/chain/chain_link/chain_link_new.c\
	./srcs/types/string/ftstring.c\
	./srcs/utils/error.c\
	./srcs/utils/get_heredoc_limiter.c\
	./srcs/utils/identifiers/is_limiter_char.c\
	./srcs/utils/identifiers/is_logicalop.c\
	./srcs/utils/identifiers/is_redirection.c\
	./srcs/utils/identifiers/is_space.c\
	./srcs/utils/identifiers/is_var_name.c\
	./srcs/utils/print_tab_free.c\
	./srcs/utils/secure_close.c\
	./srcs/utils/skip.c\
	./srcs/utils/str_extract.c\
	./srcs/utils/unquote.c\
	./srcs/main.c

OBJS =	\
	./build/smalloc.o\
	./build/cd.o\
	./build/cd_utils.o\
	./build/echo.o\
	./build/env.o\
	./build/pwd.o\
	./build/start_builtin.o\
	./build/handle_piped_cmd.o\
	./build/heredoc.o\
	./build/hd_add_back.o\
	./build/hd_add_front.o\
	./build/hd_clear.o\
	./build/hd_move.o\
	./build/hd_new.o\
	./build/hd_pop.o\
	./build/parse_heredoc.o\
	./build/tmp_fd.o\
	./build/logic_exec.o\
	./build/expand.o\
	./build/expand_core.o\
	./build/skipto.o\
	./build/syntax_operator.o\
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
	./build/syntaxer.o\
	./build/pipe_exec.o\
	./build/apply_redirection.o\
	./build/get_redirect_file.o\
	./build/get_redirection.o\
	./build/start_splitted_cmd.o\
	./build/subshell_exec.o\
	./build/chain_append.o\
	./build/chain_free.o\
	./build/chain_init.o\
	./build/chain_link_init.o\
	./build/chain_link_new.o\
	./build/ftstring.o\
	./build/error.o\
	./build/get_heredoc_limiter.o\
	./build/is_limiter_char.o\
	./build/is_logicalop.o\
	./build/is_redirection.o\
	./build/is_space.o\
	./build/is_var_name.o\
	./build/print_tab_free.o\
	./build/secure_close.o\
	./build/skip.o\
	./build/str_extract.o\
	./build/unquote.o\
	./build/main.o

DEPS =	\
	./build/smalloc.d\
	./build/cd.d\
	./build/cd_utils.d\
	./build/echo.d\
	./build/env.d\
	./build/pwd.d\
	./build/start_builtin.d\
	./build/handle_piped_cmd.d\
	./build/heredoc.d\
	./build/hd_add_back.d\
	./build/hd_add_front.d\
	./build/hd_clear.d\
	./build/hd_move.d\
	./build/hd_new.d\
	./build/hd_pop.d\
	./build/parse_heredoc.d\
	./build/tmp_fd.d\
	./build/logic_exec.d\
	./build/expand.d\
	./build/expand_core.d\
	./build/skipto.d\
	./build/syntax_operator.d\
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
	./build/syntaxer.d\
	./build/pipe_exec.d\
	./build/apply_redirection.d\
	./build/get_redirect_file.d\
	./build/get_redirection.d\
	./build/start_splitted_cmd.d\
	./build/subshell_exec.d\
	./build/chain_append.d\
	./build/chain_free.d\
	./build/chain_init.d\
	./build/chain_link_init.d\
	./build/chain_link_new.d\
	./build/ftstring.d\
	./build/error.d\
	./build/get_heredoc_limiter.d\
	./build/is_limiter_char.d\
	./build/is_logicalop.d\
	./build/is_redirection.d\
	./build/is_space.d\
	./build/is_var_name.d\
	./build/print_tab_free.d\
	./build/secure_close.d\
	./build/skip.d\
	./build/str_extract.d\
	./build/unquote.d\
	./build/main.d

$(BUILD_DIR):
	@mkdir -p $@

./build/smalloc.o: ./srcs/alloc/smalloc.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/cd.o: ./srcs/builtin/cd/cd.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/cd_utils.o: ./srcs/builtin/cd/cd_utils.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/echo.o: ./srcs/builtin/echo.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/env.o: ./srcs/builtin/env.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/pwd.o: ./srcs/builtin/pwd.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/start_builtin.o: ./srcs/builtin/start_builtin.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/handle_piped_cmd.o: ./srcs/handle_piped_cmd.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/heredoc.o: ./srcs/here_doc/heredoc.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/hd_add_back.o: ./srcs/here_doc/heredoc_list/hd_add_back.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/hd_add_front.o: ./srcs/here_doc/heredoc_list/hd_add_front.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/hd_clear.o: ./srcs/here_doc/heredoc_list/hd_clear.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/hd_move.o: ./srcs/here_doc/heredoc_list/hd_move.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/hd_new.o: ./srcs/here_doc/heredoc_list/hd_new.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/hd_pop.o: ./srcs/here_doc/heredoc_list/hd_pop.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/parse_heredoc.o: ./srcs/here_doc/parse_heredoc.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/tmp_fd.o: ./srcs/here_doc/tmp_fd.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/logic_exec.o: ./srcs/logic_exec.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/expand.o: ./srcs/parsing/expand/expand.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/expand_core.o: ./srcs/parsing/expand/expand_core.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/skipto.o: ./srcs/parsing/skipto.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_operator.o: ./srcs/parsing/syntax/syntax_operator.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_and.o: ./srcs/parsing/syntax/syntax_operator/syntax_and.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_append.o: ./srcs/parsing/syntax/syntax_operator/syntax_append.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_close.o: ./srcs/parsing/syntax/syntax_operator/syntax_close.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_dquote.o: ./srcs/parsing/syntax/syntax_operator/syntax_dquote.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_heredoc.o: ./srcs/parsing/syntax/syntax_operator/syntax_heredoc.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_in.o: ./srcs/parsing/syntax/syntax_operator/syntax_in.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_open.o: ./srcs/parsing/syntax/syntax_operator/syntax_open.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_or.o: ./srcs/parsing/syntax/syntax_operator/syntax_or.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_out.o: ./srcs/parsing/syntax/syntax_operator/syntax_out.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_pipe.o: ./srcs/parsing/syntax/syntax_operator/syntax_pipe.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntax_squote.o: ./srcs/parsing/syntax/syntax_operator/syntax_squote.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/syntaxer.o: ./srcs/parsing/syntax/syntaxer.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/pipe_exec.o: ./srcs/pipe_exec.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/apply_redirection.o: ./srcs/redirections/apply_redirection.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/get_redirect_file.o: ./srcs/redirections/get_redirect_file.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/get_redirection.o: ./srcs/redirections/get_redirection.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/start_splitted_cmd.o: ./srcs/start_splitted_cmd.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/subshell_exec.o: ./srcs/subshell_exec.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/chain_append.o: ./srcs/types/chain/chain_append.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/chain_free.o: ./srcs/types/chain/chain_free.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/chain_init.o: ./srcs/types/chain/chain_init.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/chain_link_init.o: ./srcs/types/chain/chain_link/chain_link_init.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/chain_link_new.o: ./srcs/types/chain/chain_link/chain_link_new.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/ftstring.o: ./srcs/types/string/ftstring.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/error.o: ./srcs/utils/error.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/get_heredoc_limiter.o: ./srcs/utils/get_heredoc_limiter.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/is_limiter_char.o: ./srcs/utils/identifiers/is_limiter_char.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/is_logicalop.o: ./srcs/utils/identifiers/is_logicalop.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/is_redirection.o: ./srcs/utils/identifiers/is_redirection.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/is_space.o: ./srcs/utils/identifiers/is_space.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/is_var_name.o: ./srcs/utils/identifiers/is_var_name.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/print_tab_free.o: ./srcs/utils/print_tab_free.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/secure_close.o: ./srcs/utils/secure_close.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/skip.o: ./srcs/utils/skip.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/str_extract.o: ./srcs/utils/str_extract.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/unquote.o: ./srcs/utils/unquote.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/main.o: ./srcs/main.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@
