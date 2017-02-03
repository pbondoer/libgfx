# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libgfx.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/31 05:18:12 by pbondoer          #+#    #+#              #
#    Updated: 2017/02/03 02:59:32 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base variables for GFX library
# Use with 'include /path/to/libgfx.mk'
# Make sure to define L_GFX with the path to GFX first

L_GFX		?= .

GFX_NAME	:= libgfx.a

GFX_LNK		:= -L $(L_GFX) -l gfx
GFX_INC		:= -I $(L_GFX)/includes
GFX_LIB		:= $(L_GFX)/$(GFX_NAME)

# Global variables for compilation

ifndef LIB_LNK
LIB_LNK		:=
LIB_INC		:=
endif

LIB_LNK		+= $(GFX_LNK)
LIB_INC		+= $(GFX_INC)
