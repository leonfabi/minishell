# Single tests can be run with using make and the specific name
####################################################################
#>>>>>>>>>>>>>>>>>>>>>>>>>> Basic Setup <<<<<<<<<<<<<<<<<<<<<<<<<<<#
####################################################################
.DEFAULT_GOAL := all
CC := cc

M := \033[35m
RST := \033[0m
LOG := printf "[$(M)INFO$(RST)] %s\n"

TESTS := signals lexer builtin

# define include dirs and search paths
LIBFT_DIR := ../libft
LIBFT := $(LIBFT_DIR)/libft.a
INC_DIRS := -I../include -I../libft/include
VPATH := ../src ../src/lexer ../src/signals ../src/utils ../src/builtins
VPATH += ../src/environment ../src/init ../src/expander
OBJ_DIR := ./_obj

# define compiler and linker flags
CFLAGS_TEST := -g
CFLAGS := $(CFLAGS_TEST) -MMD -MP
#TEST_FLAG := -Wno-error=unused-command-line-argument
LDFLAGS := -L $(LIBFT_DIR) -lft -lreadline -lcriterion # -Wno-write-strings -fpermissive
# define a variable to run the tests
define run
	$(CC) $^ $(INC_DIRS) $(LDFLAGS) -o $@ && ./$@ --verbose
endef

####################################################################
#>>>>>>>>>>>>>>>>>>>>>>>> Individual Setup <<<<<<<<<<<<<<<<<<<<<<<<#
####################################################################

# Source files for signals
SRC_SIGNALS := signal_handler.c 
OBJS_SIGNALS := $(addprefix $(OBJ_DIR)/, $(SRC_SIGNALS:%.c=%.o))

# Source files for lexer
SRC_LEXER := lexer.c lexer_token.c lexer_token_2.c double_list.c error_mgmt.c
OBJS_LEXER := $(addprefix $(OBJ_DIR)/, $(SRC_LEXER:%.c=%.o))

# Source files for builtins
SRC_BUILTIN := ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c
SRC_BUILTIN += exit_status.c environment_utils.c init.c ft_export_utils.c
SRC_BUILTIN += error_mgmt.c double_list.c adv_utils.c
OBJS_BUILTIN := $(addprefix $(OBJ_DIR)/, $(SRC_BUILTIN:%.c=%.o))

####################################################################
#>>>>>>>>>>>>>>>>> Here is the start of the tests <<<<<<<<<<<<<<<<<#
####################################################################

all: $(TESTS)

$(LIBFT):
	@$(MAKE) -C ../libft -B --no-print-directory

# Test cases for the lexer
.PHONY: lexer
lexer: $(OBJS_LEXER) test_lexer.c | $(LIBFT)
	@$(call run, "$^")

# Testing the signal handler for SIGINT and SIGQUIT
.PHONY: signals
signals: $(LIBFT) $(OBJS_SIGNALS) test_signals.c
	@$(call run, "$^")

# Testing the signal handler for SIGINT and SIGQUIT
.PHONY: builtin
builtin: $(OBJS_BUILTIN) test_builtin.c | $(LIBFT)
	$(CC) $^ $(INC_DIRS) $(LDFLAGS) -o $@ -g
	@$(call run, "$^")

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< $(CFLAGS_TEST) $(INC_DIRS) $(LDFLAGS) -o $@
# (CC) $(CFLAGS) $(TEST_FLAG) -c $< $(INC_DIRS) $(LDFLAGS) -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing object files"

fclean: clean
	@$(RM) $(TESTS)
	@$(LOG) "Removing executables"

-include $(OBJS:%.o=%.d)
