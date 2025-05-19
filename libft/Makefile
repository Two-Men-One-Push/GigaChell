BUILD_TYPE_FILE = .build_type.mk
MAKEFLAGS += --no-print-directory

-include $(BUILD_TYPE_FILE)

BUILD_TYPE_TARGET ?= main

NAME = libft.a
BUILD_ROOT_FOLDER = .build
BUILD_FOLDER = $(BUILD_ROOT_FOLDER)/$(BUILD_TYPE_TARGET)
HEADER_FOLDER = include
SRC_FOLDER = src


CONVERTER_FOLDER = converter
CONVERTER_FILES = ft_atoi.c \
	ft_itoa.c

FREE_FOLDER = free
FREE_FILES = free_split.c \
	free_n.c

FT_PRINTF_FOLDER = ft_printf
FT_PRINTF_FILES = ft_vfprintf.c \
	ft_printf.c \
	ft_devprintf.c \
	ft_dprintf.c \
	handle_flag.c \
	ft_vfprintf_utils.c \
	flags/flag_c.c \
	flags/flag_i.c \
	flags/flag_low_x.c \
	flags/flag_p.c \
	flags/flag_s.c \
	flags/flag_u.c \
	flags/flag_up_x.c

GET_NEXT_LINE_FOLDER = get_next_line
GET_NEXT_LINE_FILES = get_next_line.c \
	get_next_line_utils.c

IDENTIFER_FOLDER = identifier
IDENTIFER_FILES = ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isupper.c

MATHS_FOLDER = maths
MATHS_FILES = arrmax.c \
	arrmin.c \
	max.c \
	min.c \
	maxs.c \
	mins.c

LIST_FOLDER = list
LIST_FILES = lstadd_back.c \
	lstadd_front.c \
	lstclear.c \
	lstdelone.c \
	lstiter.c \
	lstlast.c \
	lstmap.c \
	lstnew.c \
	lstpop.c \
	lstsize.c

MEMORY_FOLDER = memory
MEMORY_FILES = ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdup.c \
	ft_memmove.c \
	ft_memset.c

STRING_FOLDER = string
STRING_FILES = ft_split.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strstr.c \
	ft_strtok.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_toupper.c \
	ft_tolower.c \
	starts_by.c \
	ends_by.c


VECTOR_FOLDER = vector
VECTOR_FILES = int/ivec_create.c \
	int/ivec_push.c \
	int/ivec_set.c \
	int/ivec_get.c \
	int/ivec_includes.c \
	int/ivec_index.c \
	int/ivec_pop.c \
	int/ivec_print.c \
	int/ivec_destroy.c
#	char/cvec_create.c \
#	char/cvec_destroy.c \
#	char/cvec_get.c \
#	char/cvec_pop.c \
#	char/cvec_print.c \
#	char/cvec_push.c

ENV_FOLDER = env
ENV_FILES = env_handle.c \
	env_init.c \
	env_set.c \
	env_get.c \
	env_to_envp.c \
	env_unset.c \
	env_clear.c \
	wrapper/ft_initenv.c \
	wrapper/ft_setenv.c \
	wrapper/ft_getenv.c \
	wrapper/ft_getenvp.c \
	wrapper/ft_unsetenv.c \
	wrapper/ft_clearenv.c \
	realloc_env.c

FILES = $(addprefix $(SRC_FOLDER)/, \
	$(addprefix $(CONVERTER_FOLDER)/, $(CONVERTER_FILES)) \
	$(addprefix $(FREE_FOLDER)/, $(FREE_FILES)) \
	$(addprefix $(FT_PRINTF_FOLDER)/, $(FT_PRINTF_FILES)) \
	$(addprefix $(GET_NEXT_LINE_FOLDER)/, $(GET_NEXT_LINE_FILES)) \
	$(addprefix $(IDENTIFER_FOLDER)/, $(IDENTIFER_FILES)) \
	$(addprefix $(LIST_FOLDER)/, $(LIST_FILES)) \
	$(addprefix $(MATHS_FOLDER)/, $(MATHS_FILES)) \
	$(addprefix $(MEMORY_FOLDER)/, $(MEMORY_FILES)) \
	$(addprefix $(STRING_FOLDER)/, $(STRING_FILES)) \
	$(addprefix $(VECTOR_FOLDER)/, $(VECTOR_FILES)) \
	$(addprefix $(ENV_FOLDER)/, $(ENV_FILES)) \
)

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP -I$(HEADER_FOLDER)


DEV_DEFINE = -DDEV
DEV_FLAGS = $(DEV_DEFINE) -g3

TEST_NAME = tester
TEST_FILES = main.test.c
TEST_FLAGS = $(CFLAGS) $(DEV_FLAGS)
TEST_OBJS = $(addprefix $(BUILD_FOLDER)/, $(TEST_FILES:.c=.o))
TEST_DEPS = $(addprefix $(BUILD_FOLDER)/, $(TEST_FILES:.c=.d))

.PHONY: all clean fclean re test tester dev FORCE

all: $(NAME)

ifneq ($(BUILD_TYPE),$(BUILD_TYPE_TARGET))
$(NAME): $(OBJS) FORCE
	@ar rcs $(NAME) $(OBJS)
	@echo
	@echo -e Builded : $(BOLD)$(BLUE)$(NAME)$(RESET)
	@echo
	@echo BUILD_TYPE = $(BUILD_TYPE_TARGET) > $(BUILD_TYPE_FILE)
else
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo BUILD_TYPE = $(BUILD_TYPE_TARGET) > $(BUILD_TYPE_FILE)
endif

dev: FORCE
	@$(MAKE) CFLAGS="$(TEST_FLAGS)" BUILD_TYPE_TARGET=dev

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -e $(BOLD)$(RED)Compiling$(RESET) with : $(BOLD)$(LIGHT_GREY)$(CC) $(DARK_GREY)$(CFLAGS) $(GREEN)$<$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_ROOT_FOLDER)
	@echo -e $(GREEN)Project cleaned$(RESET)

fclean:
	@rm -rf $(BUILD_ROOT_FOLDER)
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@rm -f $(BUILD_TYPE_FILE)
	@echo -e $(GREEN)Project full cleaned$(RESET)

re: fclean 
	$(MAKE) all

$(TEST_NAME): dev
	@$(MAKE) -s $(TEST_OBJS) CFLAGS="$(TEST_FLAGS)"
	@$(CC) $(TEST_FLAGS) $(TEST_OBJS) $(NAME) -o $(TEST_NAME)

test: $(TEST_NAME)
	@./$(TEST_NAME)
	@rm $(TEST_NAME)

-include $(DEPS)

BLACK		= '\e[38;5;16m'
RED			= '\e[38;5;196m'
GREEN		= '\e[38;5;46m'
YELLOW		= '\e[38;5;226m'
BLUE		= '\e[38;5;87m'
DARK_GREY	= '\e[38;5;237m'
LIGHT_GREY	= '\e[38;5;253m'
WHITE		= '\e[38;5;255m'

BOLD		= '\033[1m'
UNDERLINE	= '\033[4m'

RESET		= '\033[0m'
