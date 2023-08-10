# Single tests can be run with using make and the specific name
.DEFAULT_GOAL := all

TESTS := signals lexer

OBJ_DIR := ./_obj
SRC_DIR := ../src
# LIBFT_DIR := ../libft/lib
INC_DIR := ../include

# Specify all src file folders here
SRC_DIRS := lexer signals
SRC_DIRS := $(addprefix $(SRC_DIR)/, $(SRC_DIRS))
SRC_DIRS += $(SRC_DIR)

# Specify the search paths for source and header files
vpath %.h $(INC_DIR)
vpath %.c $(SRC_DIRS)

# Name all the source files for the unit tests
# SOURCES := lexer.c
SOURCES := signal_handler.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

CFLAGS := -Wall -Wextra -Werror -g -I $(INC_DIR) -MMD -MP
# LDFLAGS := -L $(LIBFT_DIR) -lft -lcriterion -lreadline
LDFLAGS := -lcriterion -lreadline

# define a variable to run the tests
define run
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@ && ./$@ --verbose
endef

####################################################################
#>>>>>>>>>>>>>>>>> Here is the start of the tests <<<<<<<<<<<<<<<<<#
####################################################################

all: $(TESTS) clean


.PHONY: lexer
lexer: $(OBJS) test_lexer.c
	@$(call run, "$^")

.PHONY: signals
signals: $(OBJS) test_signals.c
	@$(call run, "$^")

$(OBJ_DIR)/%.o: %.c
	mkdir -p _obj
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< $(LDFLAGS) -o $@

-include $(OBJS:%.o=%.d)
