CC = cc -g
RM = rm -f
EXE = fdf.exe
LIBNAME = custom_lib.a
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
MLX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
TESTCASE = io/test_maps/42.fdf

SRCDIR = src
LIBDIR = custom_library
INCLUDES = includes

SRCS = events.c main.c parse_file.c \
		render.c utils.c utils2.c \
		errors.c maths.c draw_1.c draw_2.c
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))
OBJS = $(SRCS:.c=.o)

all: lib $(EXE)

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