.SILENT:
MAKEFLAGS += --no-print-directory

CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= libft.a
HEADER= ./my_lib.h

G= \033[0;32m
O= \033[0;33m

all: $(HEADER)
	@make -C ./ft_printf
	@mv ./ft_printf/libftprintf.a ./$(NAME)

clean:
	@make clean -C ./ft_printf
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./ft_printf
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
