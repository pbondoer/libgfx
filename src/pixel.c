/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 23:06:47 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/03 04:13:41 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

/*
** Converts an (x, y) position into a pointer in a given image
*/

static inline int	*pos_to_ptr(t_image *restrict img, const int x, const int y)
{
	return ((int *)(img->ptr + ((x + y * img->width) * img->bpp)));
}

/*
** Checks if the given position is valid
*/

static inline int	invalid_pos(const t_image *restrict img,
								const int x,
								const int y)
{
	return (x < 0 || y < 0 || x >= img->width || y >= img->height);
}

/*
** Sets a pixel inside an image
*/

inline void			gfx_image_set_pixel(t_image *restrict image,
										int x,
										int y,
										t_color color)
{
	if (!invalid_pos(image, x, y))
		*pos_to_ptr(image, x, y) = color.value;
}

/*
** Gets a pixel inside a window
*/

inline t_color		gfx_image_get_pixel(t_image *image, int x, int y)
{
	if (invalid_pos(image, x, y))
		return ((t_color)0x0);
	return ((t_color)*pos_to_ptr(image, x, y));
}
