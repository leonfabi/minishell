# Single tests can be run with using make and the specific name
####################################################################
#>>>>>>>>>>>>>>>>>>>>>>>>>> Basic Setup <<<<<<<<<<<<<<<<<<<<<<<<<<<#
####################################################################
.DEFAULT_GOAL := all


TESTS := signals lexer

# define include dirs and search paths
# LIBFT_DIR := ../libft/lib
INC_DIR := ../include
VPATH := ../src ../src/lexer ../src/signals
vpath %.h $(INC_DIR)
OBJ_DIR := ./_obj

# define compiler and linker flags
CFLAGS := -Wall -Wextra -Werror -g -I $(INC_DIR) -MMD -MP
# LDFLAGS := -L $(LIBFT_DIR) -lft -lcriterion -lreadline
LDFLAGS := -lcriterion -lreadline

# define a variable to run the tests
define run
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@ && ./$@ --verbose
endef

####################################################################
#>>>>>>>>>>>>>>>>>>>>>>>> Individual Setup <<<<<<<<<<<<<<<<<<<<<<<<#
####################################################################

# Src files for signals
SRC_SIGNALS := signal_handler.c 
OBJS_SIGNALS := $(addprefix $(OBJ_DIR)/, $(SRC_SIGNALS:%.c=%.o))
# SRC_DIR := ../src

# Specify all src file folders here
# SRC_DIRS := lexer signals
# SRC_DIRS := $(addprefix $(SRC_DIR)/, $(SRC_DIRS))
# SRC_DIRS += $(SRC_DIR)

# Specify the search paths for source and header files
# vpath %.c $(SRC_DIRS)

# Name all the source files for the unit tests
# SOURCES := lexer.c
# SOURCES := signal_handler.c

# OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))



####################################################################
#>>>>>>>>>>>>>>>>> Here is the start of the tests <<<<<<<<<<<<<<<<<#
####################################################################

all: $(TESTS)


.PHONY: lexer
lexer: $(OBJS) test_lexer.c
	@$(call run, "$^")

.PHONY: signals
signals: $(OBJS_SIGNALS) test_signals.c
	@$(call run, "$^")

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< $(LDFLAGS) -o $@

-include $(OBJS:%.o=%.d)
