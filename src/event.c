/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 07:50:42 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/03 04:14:33 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"
#include "gfx_internal.h"
#include <stdlib.h>

/*
** Handles expose for X11 (this event won't be triggered in Cocoa)
** Simply redraw our buffer to screen
*/

int		gfx_window_hook_expose(t_window *win)
{
	gfx_window_refresh(win);
	return (0);
}

/*
** Handles window closing
** gfx->window is a list pointer so if it is NULL we closed our last window
*/

int		gfx_window_hook_close(t_window *win)
{
	t_gfx *gfx;

	gfx = win->gfx;
	gfx_close_window(win);
	if (!gfx->window)
		exit(EXIT_SUCCESS);
	return (0);
}
