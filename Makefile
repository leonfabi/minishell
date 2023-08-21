NAME := minishell
.DEFAULT_GOAL := all

##############################################################################
##############################################################################
##############################################################################

Y := \033[33m
C := \033[36m
R := \033[31m
G := \033[32m
X := \033[0m
C := \033[36m
LOG := printf "[$(G)INFO$(X)] %s\n"

##############################################################################
##############################################################################
##############################################################################

VPATH := src src/lexer src/signal src/init

CFLAGS ?= -Wextra -Wall -Werror -MMD -MP
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS	:= -I ./include -I $(LIBFT_DIR)/include
SRCS_LEXER	:= lexer.c lexer_token.c lexer_token_2.c
SRCS_LEXER	:= $(addprefix lexer/, $(SRCS_LEXER))
SRCS_UTIL	:= double_list.c error_mgmt.c
SRCS_UTIL	:= $(addprefix utils/, $(SRCS_UTIL))
SRCS_DIR	:= ./src
SRCS	:= $(addprefix $(SRCS_DIR)/, $(SRCS_LEXER)) $(addprefix $(SRCS_DIR)/, $(SRCS_UTIL))
OBJ_DIR := ./_obj
OBJ_LEXER := $(addprefix $(OBJ_DIR)/, $(SRCS_LEXER=%.c=%.o))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_LEXER)
	cc $(SRCS) $(HEADERS) -L ./libft/lib -lft -lreadline -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) -B

debug: CFLAGS += -g
debug: fclean all

clean:
	@$(MAKE) -C ./libft/ clean
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(LOG) "Cleaning $(notdir $(OBJ_DIR))"; \
		rm -rf $(OBJ_DIR); \
	else \
		$(LOG) "No objects to clean."; \
	fi

fclean: clean
	@$(MAKE) -C ./libft/ fclean
	@if [ -f "$(NAME)" ]; then \
		$(LOG) "Cleaning $(notdir $(NAME))"; \
		rm -f $(NAME); \
	else \
		$(LOG) "No library to clean."; \
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
