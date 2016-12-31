/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 07:50:42 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 08:58:44 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"
#include "gfx_internal.h"
#include <stdlib.h>

/*
** Handles expose for X11 (this event won't be triggered in Cocoa)
*/

int		gfx_window_hook_expose(t_window *win)
{
	(void)win;
	return (0);
}

/*
** Handles window closing
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
