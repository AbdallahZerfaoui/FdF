CC = cc -g
RM = rm -f
EXE = fdf.exe
LIBNAME = custom_lib.a
TESTCASE = io/test_maps/t2_.fdf
CFLAGS = -Wall -Wextra -Werror
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
# MLX = -L ./minilibx-linux -lmlx -lX11 -lXext -lm
MLX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
#MLX = -lmlx -framework OpenGL -framework AppKit

SRCDIR = src
LIBDIR = custom_library
INCLUDES = includes

SRCS = events.c main.c parse_file.c render.c utils.c utils2.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS = $(SRCS:.c=.o)

all: lib $(EXE)

# Rule to build libft
lib: 
	@$(MAKE) --no-print-directory fclean -C $(LIBDIR)
	@$(MAKE) --no-print-directory all -C $(LIBDIR)
	@echo "custom_lib library created."

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LIBNAME) $(MLX) -I $(INCLUDES)
	@echo "fdf executable created."

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

parse: all
	./$(EXE) $(TESTCASE)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(EXE)
	$(MAKE) --no-print-directory fclean -C $(LIBDIR)

re: fclean all

valgrind: all
	valgrind $(VFLAGS) ./$(EXE) $(TESTCASE)

.PHONY: all clean fclean re lib parse valgrind