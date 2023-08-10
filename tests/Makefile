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
# LIBFT_DIR := ../libft/lib
INC_DIR := ../include
VPATH := ../src ../src/lexer ../src/signals
vpath %.h $(INC_DIR)
OBJ_DIR := ./_obj

# define compiler and linker flags
CFLAGS_TEST := -Wall -Wextra -Werror -g -I $(INC_DIR)
CFLAGS := $(CFLAGS_TEST) -MMD -MP
# LDFLAGS := -L $(LIBFT_DIR) -lft -lcriterion -lreadline
LDFLAGS := -lcriterion -lreadline

# define a variable to run the tests
define run
	$(CC) $(CFLAGS_TEST) $^ $(LDFLAGS) -o $@ && ./$@ --verbose
endef

####################################################################
#>>>>>>>>>>>>>>>>>>>>>>>> Individual Setup <<<<<<<<<<<<<<<<<<<<<<<<#
####################################################################

# Src files for signals
SRC_SIGNALS := signal_handler.c 
OBJS_SIGNALS := $(addprefix $(OBJ_DIR)/, $(SRC_SIGNALS:%.c=%.o))

####################################################################
#>>>>>>>>>>>>>>>>> Here is the start of the tests <<<<<<<<<<<<<<<<<#
####################################################################

all: $(TESTS)

.PHONY: lexer
lexer: $(OBJS) test_lexer.c
	@$(call run, "$^")

# Testing the signal handler for SIGINT and SIGQUIT
.PHONY: signals
signals: $(OBJS_SIGNALS) test_signals.c
	@$(call run, "$^")

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< $(LDFLAGS) -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing object files"

fclean: clean
	@$(RM) $(TESTS)
	@$(LOG) "Removing executables"

-include $(OBJS:%.o=%.d)
