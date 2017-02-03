# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/31 04:57:48 by pbondoer          #+#    #+#              #
#    Updated: 2017/02/03 02:54:35 by pbondoer         ###   ########.fr        #
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

#LIB_INC		:=
#LIB_LNK		:=

include $(L_MLX)/libmlx.mk
include $(L_GFX)/libgfx.mk
include $(L_FT)/libft.mk

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(LIB_INC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
