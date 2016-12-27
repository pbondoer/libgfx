/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 23:06:47 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/28 00:25:39 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

/*
** Converts an (x, y) position into a pointer in a given image
*/

static int	*pos_to_ptr(t_image *img, int x, int y)
{
	return ((int *)(img->ptr + ((x + y * img->width) * img->bpp)));
}

/*
** Checks if the given position is valid
*/

static int	invalid_pos(t_image *img, int x, int y)
{
	return (x < 0 || y < 0 || x >= img->width || y >= img->height);
}

/*
** Sets a pixel inside an image
*/

void		gfx_image_set_pixel(t_image *image, int x, int y, t_color color)
{
	if (!invalid_pos(image, x, y))
		*pos_to_ptr(image, x, y) = color.value;
}

/*
** Gets a pixel inside a window
*/

t_color		gfx_image_get_pixel(t_image *image, int x, int y)
{
	if (invalid_pos(image, x, y))
		return ((t_color)0x0);
	return ((t_color)*pos_to_ptr(image, x, y));
}
