/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 09:49:19 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/03 04:17:02 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_internal.h"
#include "libgfx.h"

/*
** Checks if a point is inside a given size (assuming 0,0 min)
*/

inline int		point_in_bounds(const t_point *restrict p,
								const int w,
								const int h)
{
	return (p->x >= 0 && p->x < w && p->y >= 0 && p->y < h);
}

/*
** Checks if a point is inside a rectangle
*/

inline int		point_in_rectangle(const t_point *restrict p,
									const t_point min,
									const t_point max)
{
	return (p->x >= min.x && p->x < max.x && p->y >= min.y && p->y < max.y);
}
