EXE = fdf.exe
LIBNAME = custom_lib.a
TESTCASE = io/test_logo3.fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
# MLX = -L ./minilibx-linux -lmlx -lX11 -lXext -lm
MLX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
#MLX = -lmlx -framework OpenGL -framework AppKit

SRCDIR = src
LIBDIR = custom_library
INCLUDES = includes

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: lib_only $(EXE)

# Rule to build libft
lib: 
	@$(MAKE) --no-print-directory fclean -C $(LIBDIR)
	@$(MAKE) --no-print-directory all -C $(LIBDIR)
	@echo "custom_lib library created."

lib_only: lib
	@$(MAKE) --no-print-directory clean -C $(LIBDIR)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(EXE) $(OBJS) $(LIBNAME) $(MLX) -I $(INCLUDES)
	@echo "fdf executable created."

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

parse: all
	./$(EXE) $(TESTCASE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXE)
	$(MAKE) --no-print-directory fclean -C $(LIBDIR)

re: fclean all

valgrind: all
	valgrind --leak-check=full ./$(EXE) $(TESTCASE)
# --leak-check=full
# --show-leak-kinds=all

.PHONY: all clean fclean re lib lib_only parse valgrind