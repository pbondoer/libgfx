# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gfx.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/31 05:18:12 by pbondoer          #+#    #+#              #
#    Updated: 2016/12/31 05:24:07 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base variables for GFX library
# Use with 'include /path/to/gfx.mk'
# Make sure to define L_GFX with the path to GFX first

ifndef L_GFX
	L_GFX	= .
endif

GFX_NAME	= libgfx.a

GFX_LNK		= -L $(L_GFX) -l gfx
GFX_INC		= -I $(L_GFX)/includes
GFX_LIB		= $(L_GFX)/$(GFX_NAME)
