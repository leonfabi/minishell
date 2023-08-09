NAME := minishell
TEST := test
.DEFAULT_GOAL := all

VPATH := src src/lexer src/signal tests

CFLAGS ?= -Wextra -Wall -Werror -MMD -MP
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS	:= -I ./include -I $(LIBFT_DIR)/header
LIBS	:= $(LIBFT)
SRCS_LEXER	:= lexer.c
SRCS	:= $(SRCS_LEXER)
OBJ_DIR := ./_obj
OBJ_LEXER := $(addprefix $(OBJ_DIR)/, $(SRCS_LEXER=%.c=%.o))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME) $(LIBFT)

test: $(OBJ_LEXER)
	cc ./tests/test_lexer.c -lreadline -o ./tests/test_lexer
	./tests/test_lexer 

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