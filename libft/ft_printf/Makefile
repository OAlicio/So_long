.SILENT:
NAME          = libftprintf.a
CC            = cc
CFLAGS        = -Wall -Wextra -Werror
AR            = ar rcs
RM            = rm -f
HEADER        = printf.h
SRC           = ft_aux.c ft_printf.c ft_putchar.c \
	    ft_puthexa.c ft_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ../libft
	@mv ../libft/libft.a ./$(NAME)
	@$(AR) $(NAME) $(OBJ) 

$(OBJ): $(HEADER)

clean:
	@make clean -C ../libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ../libft
	@$(RM) $(NAME)

re: fclean all
