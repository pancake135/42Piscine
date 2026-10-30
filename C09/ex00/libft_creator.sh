#!/bin/sh

NAME="libft.a"
CC="cc"
CFLAGS="-Wall -Wextra -Werror"

SRCS="ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c"

$CC $CFLAGS -c $SRCS

ar rcs libft.a *.o

rm -f *.o