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
SRCS := main.c utils/exit.c src/parce.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

# Link the object files to create the executable
$(NAME): $(OBJS)
	$(QUIET)$(CC) $(OBJS) $(MLX_LIB) -o $(NAME)

# Object file generation rules
%.o: %.c
	$(QUIET)$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -c $< -o $@

# Clean rules
clean:
	$(QUIET)$(RM) $(OBJS)

fclean: clean
	$(QUIET)$(RM) $(NAME)

# Rebuild rules
re: fclean all

.PHONY: all clean fclean re