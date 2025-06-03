NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM := rm -f

# Define path to the library
QUIET ?= @

.c.o:
	$(QUIET)${CC} ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(QUIET)$(AR) $(NAME) $(OBJS)

clean:
	$(QUIET)${RM} $(OBJS)

fclean: clean
	$(QUIET)${RM} $(NAME)

re: fclean all