# Single tests can be run with using make and the specific name
####################################################################
#>>>>>>>>>>>>>>>>>>>>>>>>>> Basic Setup <<<<<<<<<<<<<<<<<<<<<<<<<<<#
####################################################################
.DEFAULT_GOAL := all

M := \033[35m
RST := \033[0m
LOG := printf "[$(M)INFO$(RST)] %s\n"

TESTS := signals lexer

# define include dirs and search paths
LIBFT_DIR := ../libft/lib
INC_DIRS := -I../include -I../libft/header
VPATH := ../src ../src/lexer ../src/signals ../src/utils
OBJ_DIR := ./_obj

# define compiler and linker flags
CFLAGS_TEST := -Wall -Wextra -Werror -g
CFLAGS := $(CFLAGS_TEST) -MMD -MP
#TEST_FLAG := -Wno-error=unused-command-line-argument
LDFLAGS := -L $(LIBFT_DIR) -lft -lreadline -lcriterion
#  -lcriterion
# define a variable to run the tests
define run
	$(CC) $^ $(INC_DIRS) $(LDFLAGS) -o $@ && ./$@ --verbose
endef

# $(CC) $(CFLAGS_TEST) $^ $(INC_DIRS) $(LDFLAGS) -o $@ && ./$@ --verbose
####################################################################
#>>>>>>>>>>>>>>>>>>>>>>>> Individual Setup <<<<<<<<<<<<<<<<<<<<<<<<#
####################################################################

# Source files for signals
SRC_SIGNALS := signal_handler.c 
OBJS_SIGNALS := $(addprefix $(OBJ_DIR)/, $(SRC_SIGNALS:%.c=%.o))

# Source files for lexer
SRC_LEXER := lexer.c lexer_token.c lexer_token_2.c double_list.c error_mgmt.c
OBJS_LEXER := $(addprefix $(OBJ_DIR)/, $(SRC_LEXER:%.c=%.o))

####################################################################
#>>>>>>>>>>>>>>>>> Here is the start of the tests <<<<<<<<<<<<<<<<<#
####################################################################

all: $(TESTS)

# Test cases for the lexer
.PHONY: lexer
lexer: $(OBJS_LEXER) test_lexer.c
	@$(call run, "$^")

# Testing the signal handler for SIGINT and SIGQUIT
.PHONY: signals
signals: $(OBJS_SIGNALS) test_signals.c
	@$(call run, "$^")

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< $(INC_DIRS) $(LDFLAGS) -o $@
# (CC) $(CFLAGS) $(TEST_FLAG) -c $< $(INC_DIRS) $(LDFLAGS) -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing object files"

fclean: clean
	@$(RM) $(TESTS)
	@$(LOG) "Removing executables"

-include $(OBJS:%.o=%.d)
