# Project: so_long
MAKEFLAGS += --no-print-directory
NAME := so_long

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

# MLX
MLX_DIR := mlx_linux
MLX_NAME := mlx_Linux
MLX_LIB := -L$(MLX_DIR) -l$(MLX_NAME) -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

# Function to set show commands or not
QUIET = $(if $(filter 0,$(VERBOSE)),@,)

# Files
SRCS := solong.c
OBJ := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(QUIET)$(CC) $(OBJ) $(MLX_LIB) -o $(NAME)

# Object file generation rules
%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@

clean:
	$(QUIET)$(RM) $(OBJ)

fclean: clean
	$(QUIET)$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re