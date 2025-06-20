BUILD_DIR			=	./build/
HEADERS_DIR			=	./headers/ ./libft/include/
SRCS_DIR			=	./srcs/

MKCONFIGURE			=	./configure.mk
MKGENERATED			=	./generated.mk
MKIMPROVED			=	./improved.mk

LIBFT_DIR			=	./libft/
LIBFT_ARCHIVE		=	$(LIBFT_DIR)libft.a

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -g3 -O3 -march=native
LIBS				=	-lreadline -L$(LIBFT_DIR) -l$(patsubst lib%,%,$(notdir $(basename $(LIBFT_ARCHIVE))))

NAME				=	GigaChell

all: $(NAME)
	@echo -e
	@echo -e $(FGREEN)Success$(RESET)

-include $(DEPS) $(MKCONFIGURE) $(MKGENERATED)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE)
	@echo -e $(FRED)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ $(OBJS) $(LIBS)
	@echo -e $(FGREEN)compiling $@$(RESET)

$(LIBFT_ARCHIVE): FORCE
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY : all clean fclean re FORCE