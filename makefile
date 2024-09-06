# compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

# output names
APP = clistrutils     # Output executable name
LIB = libstrUtils.a   # Static library name

# source files
MAIN_SRC = clistrutils.c
LIB_SRC = strUtils.c

# object files
MAIN_OBJ = $(MAIN_SRC:.c=.o)
LIB_OBJ = $(LIB_SRC:.c=.o)

# include paths
INCLUDES = -I.

# compile the application
all: $(APP)

# rule to build the main application linking with the static library
$(APP): $(MAIN_OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L. -lstrUtils

# rule to create the static library from the object file of the module
$(LIB): $(LIB_OBJ)
	ar rcs $@ $^

# compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean up object files and binaries
clean:
	rm -f $(APP) $(LIB) $(MAIN_OBJ) $(LIB_OBJ)

