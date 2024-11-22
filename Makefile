NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c \
        ft_charbased.c \
		ft_hexbased.c \
		ft_intbased.c

OBJ = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(OBJ) : ft_printf.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re