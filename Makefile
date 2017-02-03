# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2017/02/03 04:31:54 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include libgfx.mk

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
CFLAGS += -O3 -march=native -pipe

# libraries
L_MLX	= ../miniLibX
L_FT	= ../libft
include $(L_MLX)/libmlx.mk
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

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
