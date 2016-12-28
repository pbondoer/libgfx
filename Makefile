# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2016/12/28 01:04:34 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgfx.a

# directories
SRC_DIR = ./src
INC_DIR = ./includes
OBJ_DIR = ./obj

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

# libraries
L_MLX	= ../miniLibX
L_FT	= ../libft

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(L_FT) -I $(L_MLX) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
