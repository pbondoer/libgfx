# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2016/12/31 10:10:49 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include gfx.mk

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
		  pixel.c \
		  event.c \
		  line.c \
		  lineclip.c \
		  hittest.c

OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# libraries
L_MLX	= ../miniLibX
L_FT	= ../libft
include $(L_MLX)/mlx.mk
include $(L_FT)/libft.mk

all: obj $(GFX_NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) $(MLX_INC) $(GFX_INC) -o $@ -c $<

$(GFX_NAME): $(OBJ)
	ar rc $(GFX_NAME) $(OBJ)
	ranlib $(GFX_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(GFX_NAME)

re: fclean all
