/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 04:21:40 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/27 23:08:53 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "libgfx.h"

/*
** Destroys an image
*/

t_image		*gfx_free_image(t_gfx *gfx, t_image *img)
{
	if (!img)
		return (NULL);
	if (img->image && gfx)
		mlx_destroy_image(gfx->mlx, img->image);
	ft_memdel((void **)&img);
	return (NULL);
}

/*
** Creates a new image
*/

t_image		*gfx_image(t_gfx *gfx, int width, int height)
{
	t_image		*img;

	if ((img = (t_image *)ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image = mlx_new_image(gfx->mlx, width, height)) == NULL)
		return (gfx_free_image(gfx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
		&img->endian);
	img->bpp /= 8;
	img->width = width;
	img->height = height;
	return (img);
}
