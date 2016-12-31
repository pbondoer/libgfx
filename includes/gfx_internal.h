/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 07:50:22 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 10:19:24 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** These are internal functions used by GFX
*/

#ifndef GFX_INTERNAL_H
# define GFX_INTERNAL_H

# include "libgfx.h"

/*
** Internal structure to perform line drawing
*/

typedef struct		s_line
{
	t_point		p1;
	t_point		p2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}					t_line;

/*
** Base hooks
*/

int		gfx_window_hook_expose(t_window *win);
int		gfx_window_hook_close(t_window *win);

/*
** Line and point functions
*/

int		lineclip(t_point *p1, t_point *p2, int w, int h);
int		point_in_bounds(t_point *p, int w, int h);
int		point_in_rectangle(t_point *p, t_point min, t_point max);
#endif
