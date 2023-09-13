NAME := minishell
.DEFAULT_GOAL := all
CC := cc

################################################################################
################################################################################
################################################################################

G := \033[32m
X := \033[0m
BO := $(shell tput bold)
LOG := printf "[$(BO)$(G)ⓘ INFO$(X)] %s\n"

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj
LIBFT_DIR := libft
INC_DIRS := include $(LIBFT_DIR)/include
SRC_DIRS := builtins core environment executor expander
SRC_DIRS := init lexer parser signals utils
SRC_DIRS := $(addprefix src/, $(SRC_DIRS))
SRC_DIRS += src

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

LIBFT = $(LIBFT_DIR)/libft.a

SRCS := ft_cd.c ft_echo.c ft_env.c ft_exit.c
SRCS += ft_export.c ft_export_utils.c ft_pwd.c ft_unset.c
SRCS += minishell.c
SRCS += environment_utils.c
SRCS += executor.c
SRCS += expander_main.c expander_utils.c
SRCS += init.c
SRCS += lexer.c lexer_token.c lexer_token_2.c
SRCS += parser_constructor_utils.c parser_constructors.c 
SRCS += parser_helpers.c parser_helpers_tok.c parser_main.c
SRCS += exit_status.c signal_handler.c
SRCS += clean_utils.c cleanup.c double_list.c error_mgmt.c
# SRCS += main_testing.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

################################################################################
########                         COMPILING                      ################
################################################################################

CFLAGS ?= -g -MMD -MP $(addprefix -I, $(INC_DIRS)) # -Wextra -Wall -Werror 
LDFLAGS := -L $(LIBFT_DIR) -lft -lreadline

################################################################################
################################################################################
# ONLY FOR TESTING PURPOSES
LDFLAGS += -lm
################################################################################
################################################################################

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT)
	@$(LOG) "Linking object files to $@"
	@$(CC) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $@)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(LOG) "Creating object directory."
	@mkdir -p $@

$(LIBFT):
	@make -C $(LIBFT_DIR) -B --no-print-directory

debug: CFLAGS += -g
debug: fclean all

clean:
	@$(MAKE) -C ./libft/ clean --no-print-directory
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(LOG) "Cleaning $(notdir $(OBJ_DIR))"; \
		rm -rf $(OBJ_DIR); \
	else \
		$(LOG) "No objects to clean."; \
	fi

fclean: clean
	@$(MAKE) -C ./libft/ fclean --no-print-directory
	@if [ -f "$(NAME)" ]; then \
		$(LOG) "Cleaning $(notdir $(NAME))"; \
		rm -f $(NAME); \
	else \
		$(LOG) "No library to clean."; \
	fi

re: fclean all

-include $(OBJS:%.o=%.d)

.PHONY: all fclean clean re
