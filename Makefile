NAME := minishell
TEST := test
.DEFAULT_GOAL := all

VPATH := src src/lexer src/signal tests

CFLAGS ?= -Wextra -Wall -Werror -MMD -MP
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/lib/libft.a
HEADERS	:= -I ./include -I $(LIBFT_DIR)/header
LIBS	:= $(LIBFT)
SRCS_LEXER	:= lexer.c lexer_token.c lexer_token_2.c
SRCS_LEXER	:= $(addprefix lexer/, $(SRCS_LEXER))
SRCS_BUILTIN	:= echo.c pwd.c
SRCS_BUILTIN	:= $(addprefix builtins/, $(SRCS_BUILTIN))
SRCS_UTIL	:= double_list.c error_mgmt.c
SRCS_UTIL	:= $(addprefix utils/, $(SRCS_UTIL))
SRCS_DIR	:= ./src
SRCS	:= $(addprefix $(SRCS_DIR)/, $(SRCS_LEXER)) $(addprefix $(SRCS_DIR)/, $(SRCS_UTIL)) $(addprefix $(SRCS_DIR)/, $(SRCS_BUILTIN))
OBJ_DIR := ./_obj
OBJ_LEXER := $(addprefix $(OBJ_DIR)/, $(SRCS_LEXER=%.c=%.o))
OBJ_BUILTIN := $(addprefix $(OBJ_DIR)/, $(SRCS_BUILTIN=%.c=%.o))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(LIBFT) $(NAME)

# $(TEST): $(OBJ_LEXER)
# 	cc ./tests/test_lexer.c $(SRCS) -lreadline $(HEADERS) -L ./libft/lib -lft -o ./tests/test_lexer
# 	./tests/test_lexer

$(TEST): $(OBJ_BUILTIN)
	@cc ./tests/test_builtin.c $(SRCS) -lreadline $(HEADERS) -L ./libft/lib -lft -o ./src/builtins/test_builtin
	@./src/builtins/test_builtin

$(NAME): $(OBJ_LEXER)
	cc $(SRCS) $(HEADERS) -L ./libft/lib -lft -lreadline -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) -B

debug: CFLAGS += -g
debug: fclean all

clean:
	@$(MAKE) -C ./libft/ clean
	@if [ -d "$(OBJ_DIR)" ]; then \
		echo $(M)Cleaning $(OBJ_DIR).$(X); \
		rm -rf $(OBJ_DIR); \
	else \
		echo $(C)No objects to clean.$(X); \
	fi

fclean: clean
	@$(MAKE) -C ./libft/ fclean
	@if [ -f "$(NAME)" ]; then \
		echo $(M)Cleaning $(NAME).$(X); \
		rm -f $(NAME); \
	else \
		echo $(C)No binary to clean.$(X); \
	fi

re: fclean all

R := "\033[31m"
G := "\033[32m"
Y := "\033[33m"
M := "\033[35m"
C := "\033[36m"
X := "\033[0m"

-include $(OBJS:%.o=%.d)

.PHONY: test