# Project: so_long
MAKEFLAGS += --no-print-directory
NAME := so_long

# Compiler and flags
CC := cc
#CFLAGS := -Wall -Wextra -Werror -O3
RM := rm -f

# MLX
MLX_DIR := minilibx-linux
MLX_NAME := mlx
MLX_LIB := -L$(MLX_DIR) -l$(MLX_NAME) -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

# Function to set show commands or not
QUIET = $(if $(filter 0,$(VERBOSE)),@,)

# Files
SRCS := main.c utils/exit.c src/init.c src/parse.c src/render.c src/init_images.c

OBJS := $(SRCS:.c=.o)

LIBFT := libft/libft.a
GNL := get_next_line/get_next_line.a

all: $(NAME)

# Link the object files to create the executable
$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(QUIET)$(CC) $(OBJS) $(LIBFT) $(GNL) $(MLX_LIB) -o $(NAME)

# Object file generation rules
%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	$(QUIET)make -C libft fclean
	$(QUIET)make -C libft

$(GNL):
	$(QUIET)make -C get_next_line fclean
	$(QUIET)make -C get_next_line

# Clean rules
clean:
	$(QUIET)$(RM) $(OBJS)
	$(QUIET)make clean -C libft
	$(QUIET)make clean -C get_next_line

fclean: clean
	$(QUIET)$(RM) $(NAME)
	$(QUIET)make fclean -C libft
	$(QUIET)make fclean -C get_next_line

# Rebuild rules
re: fclean all

.PHONY: all clean fclean re