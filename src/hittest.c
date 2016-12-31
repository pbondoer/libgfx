/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 09:49:19 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 10:16:41 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_internal.h"
#include "libgfx.h"

/*
** Checks if a point is inside a given size (assuming 0,0 min)
*/

int		point_in_bounds(t_point *p, int w, int h)
{
	return (p->x >= 0 && p->x < w && p->y >= 0 && p->y < h);
}

/*
** Checks if a point is inside a rectangle
*/

int		point_in_rectangle(t_point *p, t_point min, t_point max)
{
	return (p->x >= min.x && p->x < max.x && p->y >= min.y && p->y < max.y);
}
