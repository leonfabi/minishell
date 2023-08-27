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
SRC_DIRS := builtins init lexer signals utils
SRC_DIRS := $(addprefix src/, $(SRC_DIRS))
SRC_DIRS += src

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

LIBFT = $(LIBFT_DIR)/libft.a

SRCS := cd.c echo.c env.c exit.c export.c pwd.c unset.c
SRCS += init.c
SRCS += lexer.c lexer_token.c lexer_token_2.c
SRCS += signal_handler.c
SRCS += double_list.c error_mgmt.c
SRCS += main.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

################################################################################
########                         COMPILING                      ################
################################################################################

CFLAGS ?= -g -MMD -MP $(addprefix -I, $(INC_DIRS)) # -Wextra -Wall -Werror 
LDFLAGS := -L $(LIBFT_DIR) -lft -lreadline


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

-include $(OBJS:%.o=%.d)

.PHONY: all fclean clean re
