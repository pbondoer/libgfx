/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 22:41:08 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/28 00:23:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "libgfx.h"

/*
** Gets the next unique window identifier
*/

static int		get_window_id(void)
{
	static int	cur = 0;

	cur++;
	return (cur);
}

/*
** Destroys a window
*/

t_window		*gfx_free_window(t_gfx *gfx, t_window *win)
{
	if (!win)
		return (NULL);
	if (win->ptr && gfx)
		mlx_destroy_window(gfx, win->ptr);
	if (win->title)
		ft_strdel(&(win->title));
	if (win->buf)
		gfx_free_image(win->buf);
	ft_memdel((void **)&win);
	return (NULL);
}

/*
** Creates a new window with the associated buffers
*/

t_window		*gfx_window(t_gfx *gfx, int width, int height, char *title)
{
	t_window *win;

	if ((win = (t_window *)ft_memalloc(sizeof(t_window))) == NULL)
		return (NULL);
	if ((win->ptr = mlx_new_window(gfx->mlx, width, height, title)) == NULL ||
			(win->title = ft_strdup(title)) == NULL ||
			(win->buf = gfx_image(gfx, width, height)) == NULL)
		return (gfx_window_free(win));
	win->id = get_window_id();
	win->width = width;
	win->height = height;
	return (win);
}
