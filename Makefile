EXE = fdf.exe
LIBNAME = custom_lib.a
TESTCASE = io/test1.fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
MLX = -L ./minilibx-linux -lmlx -lX11 -lXext -lm
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
	@$(CC) $(CFLAGS) -I $(INCLUDES) $(MLX) -g -o $(EXE) $(OBJS) $(LIBNAME)
	@echo "fdf executable created."

parse: all
	./$(EXE) $(TESTCASE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXE)

re: fclean all

valgrind: all
	valgrind --leak-check=full ./$(EXE) $(TESTCASE)

.PHONY: all clean fclean re lib lib_only