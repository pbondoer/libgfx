# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/31 04:57:48 by pbondoer          #+#    #+#              #
#    Updated: 2016/12/31 08:09:11 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= gfxtest

SRC			= main.c
OBJ			= $(SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

L_MLX		= ../../miniLibX
L_FT		= ../../libft
L_GFX		= ..

include $(L_MLX)/mlx.mk
include $(L_GFX)/gfx.mk
include $(L_FT)/libft.mk

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(FT_INC) $(MLX_INC) $(GFX_INC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) $(MLX_LNK) $(GFX_LNK) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
