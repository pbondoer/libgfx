/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 06:06:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 10:17:54 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"
#include "gfx_internal.h"
#include "libft.h"

/*
** Draws a line to a window
*/

void		gfx_line_window(t_window *win, t_point p1, t_point p2, t_color c)
{
	gfx_line(win->buf, p1, p2, c);
}

/*
** Draws a line to an image
*/

void		gfx_line(t_image *img, t_point p1, t_point p2, t_color c)
{
	t_line	line;

	if (!lineclip(&p1, &p2, img->width, img->height))
		return ;
	line.dx = ft_abs(p2.x - p1.x);
	line.sx = (p1.x < p2.x ? 1 : -1);
	line.dy = ft_abs(p2.y - p1.y);
	line.sy = (p1.y < p2.y ? 1 : -1);
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (point_in_bounds(&p1, img->width, img->height)
		&& point_in_bounds(&p2, img->width, img->height))
	{
		gfx_image_set_pixel(img, p1.x, p1.y, c);
		line.err2 = line.err;
		if (line.err2 > -line.dx)
		{
			line.err -= line.dy;
			p1.x += line.sx;
		}
		if (line.err2 < line.dy)
		{
			line.err += line.dx;
			p1.y += line.sy;
		}
	}
}
