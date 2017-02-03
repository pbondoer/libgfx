/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineclip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 07:45:40 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/03 04:16:43 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"
#define R_BOTTOM	1
#define R_TOP		2
#define R_RIGHT		4
#define R_LEFT		8

/*
** Helper function to get a t_point with a size
*/

static inline t_point	size(const int w, const int h)
{
	return ((t_point){.x = w, .y = h});
}

/*
** Gets the region (top, bottom), (left, right)
*/

static inline int		region(const int x, const int y,
							const int w, const int h)
{
	int c;

	c = 0;
	if (y >= h)
		c |= R_BOTTOM;
	else if (y < 0)
		c |= R_TOP;
	if (x >= w)
		c |= R_RIGHT;
	else if (x < 0)
		c |= R_LEFT;
	return (c);
}

/*
** Clips the lines according to the region codes
*/

static t_point			clip_xy(const t_point *restrict p1,
								const t_point *restrict p2,
								const t_point size,
								const int rout)
{
	t_point p;

	if (rout & R_BOTTOM)
	{
		p.x = p1->x + (p2->x - p1->x) * (size.y - p1->y) / (p2->y - p1->y);
		p.y = size.y - 1;
	}
	else if (rout & R_TOP)
	{
		p.x = p1->x + (p2->x - p1->x) * -p1->y / (p2->y - p1->y);
		p.y = 0;
	}
	else if (rout & R_RIGHT)
	{
		p.x = size.x - 1;
		p.y = p1->y + (p2->y - p1->y) * (size.x - p1->x) / (p2->x - p1->x);
	}
	else
	{
		p.x = 0;
		p.y = p1->y + (p2->y - p1->y) * -p1->x / (p2->x - p1->x);
	}
	return (p);
}

/*
** Implementation of the Cohen–Sutherland line-clipping algorithm
*/

int						lineclip(t_point *restrict p1,
								t_point *restrict p2,
								const int w,
								const int h)
{
	t_point		p;
	int			r1;
	int			r2;
	int			rout;

	r1 = region(p1->x, p1->y, w, h);
	r2 = region(p2->x, p2->y, w, h);
	while (!(!(r1 | r2) || (r1 & r2)))
	{
		rout = r1 ? r1 : r2;
		p = clip_xy(p1, p2, size(w, h), rout);
		if (rout == r1)
		{
			p1->x = p.x;
			p1->y = p.y;
			r1 = region(p1->x, p1->y, w, h);
		}
		else
		{
			p2->x = p.x;
			p2->y = p.y;
			r2 = region(p2->x, p2->y, w, h);
		}
	}
	return (!(r1 | r2));
}
