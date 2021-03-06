/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 23:14:46 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/03 04:12:24 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libgfx.h"
#include "mlx.h"

/*
** Clears an image to black pixels / empty data
*/

inline void	gfx_image_clear(t_image *image)
{
	ft_bzero(image->ptr, image->width * image->height * image->bpp);
}

/*
** Clears a window's buffer
*/

inline void	gfx_window_clear(t_window *win)
{
	gfx_image_clear(win->buf);
}

/*
** Repaints the butter to the current window
*/

void		gfx_window_refresh(t_window *win)
{
	mlx_put_image_to_window(win->gfx->mlx, win->ptr, win->buf->image, 0, 0);
	mlx_do_sync(win->gfx->mlx);
}
