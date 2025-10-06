# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 11:34:45 by ofeverei          #+#    #+#              #
#    Updated: 2025/09/29 17:32:09 by ofeverei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
MAKEFLAGS += 	   --no-print-directory

CC=          	   cc
CFLAGS=      	   -Wall -Wextra -Werror -I$(MLX_DIR)
MFLAGS=      	   -lXext -lX11
NAME=        	   so_long
INC_DIR=     	   ./includes
SRC_DIR=     	   ./src

SRC=         $(SRC_DIR)/main.c\
	               $(SRC_DIR)/flood_fill.c\
	               $(SRC_DIR)/map_render.c\
	               $(SRC_DIR)/movement.c\
	         	   $(SRC_DIR)/game_handler.c\
			 	   $(SRC_DIR)/create_img.c\
			 	   $(SRC_DIR)/free.c $(SRC_DIR)/aux.c 
OBJ=         	   $(SRC:.c=.o)
HEADER=      	   $(INC_DIR)/so_long.h
HEADER2=     	   ./libft/my_lib.h

LIB=         	   libft.a

MLX_DIR= ./minilibx-linux
MLX_LIB= $(MLX_DIR)/libmlx_Linux.a


O= \033[0;33m

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	@make -C ./libft
	@mv ./libft/$(LIB) ./$(LIB)
	@$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib $(MFLAGS) -o $(NAME) $(LIB)
	@rm -rf $(LIB)
	@clear; echo "$(O)TIME TO PLAY"

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(OBJ): $(HEADER) $(HEADER2)

clean: 
	@rm -rf $(OBJ)
	@make clean -C ./libft
	@make clean -C $(MLX_DIR)
	@echo "Objects removed"

fclean: clean
	@rm -rf $(LIB) $(NAME)
	@make fclean -C ./libft
	@echo "Program removed"

re: fclean all

.PHONY: all bonus clean fclean
