NAME = ../custom_lib.a       # The name of the custom library

CC = gcc                 	 # Compiler
CFLAGS = -Wall -Wextra -Werror  # Compilation flags

# Directories
SRCDIR = custom_library       # Directory for source files
OBJDIR = obj/lib             # Directory for object files
INCLUDES = includes      # Directory for header files

# Files
SRCS = $(wildcard *.c)  # All C files in src directory
OBJS = $(SRCS:.c=.o) # Object files for push_swap

# Targets

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

.PHONY: all clean fclean