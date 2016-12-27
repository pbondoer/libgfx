# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2016/12/28 00:34:10 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include miniLibX/mlx.mk

NAME	= libgfx.a

# directories
SRC_DIR = ./src
INC_DIR = ./includes
OBJ_DIR = ./obj
LIB_DIR = ./lib

# src / obj files
SRC		= init.c \
		  image.c \
		  window.c \
		  color.c \
		  paint.c \
		  pixel.c

OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I $(INC_DIR)

# libraries
L_MLX	= ./miniLibX
L_FT	= ./libft

# libft
FT_LIB	= $(addprefix $(L_FT)/,libft.a)
FT_INC	= -I $(L_FT)

all: obj $(L_FT) $(L_MLX) $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) $(INC) -o $@ -c $<

$(L_FT):
	@make -C $(L_FT)

$(L_MLX):
	@make -C $(L_MLX)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)
	make -C $(L_FT) clean
	make -C $(L_MLX) clean

fclean: clean
	rm -f $(NAME)
	make -C $(L_FT) fclean
	make -C $(L_MLX) fclean

re: fclean all
