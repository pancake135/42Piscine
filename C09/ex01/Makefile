NAME=libft.a

CC=cc
CFLAGS=-Wall -Wextra -Werror -I $(INCDIR)

SRCDIR = srcs
INCDIR = includes

SRCS=	$(SRCDIR)/ft_putchar.c \
 		$(SRCDIR)/ft_putstr.c \
		$(SRCDIR)/ft_strcmp.c \
		$(SRCDIR)/ft_strlen.c \
		$(SRCDIR)/ft_swap.c

OBJS = $(SRCS:.c=.o)

HEADER = $(INCDIR)/ft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
