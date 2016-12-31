/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 22:41:08 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 08:58:34 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "libgfx.h"
#include "gfx_internal.h"

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

t_window		*gfx_free_window(t_window *win)
{
	if (!win)
		return (NULL);
	if (win->ptr)
		mlx_destroy_window(win->gfx->mlx, win->ptr);
	if (win->title)
		ft_strdel(&(win->title));
	if (win->buf)
		gfx_free_image(win->gfx, win->buf);
	ft_memdel((void **)&win);
	return (NULL);
}

/*
** Closes a window
*/

void			gfx_close_window(t_window *win)
{
	if (!win)
		return ;
	ft_lstremove(&(win->gfx->window), win);
	gfx_free_window(win);
}

/*
** Base hooks for new windows
*/

static void		do_hooks(t_window *win)
{
	mlx_expose_hook(win->ptr, gfx_window_hook_expose, win);
	mlx_hook(win->ptr, 17, 1L << 0, gfx_window_hook_close, win);
}

/*
** Creates a new window with the associated buffers
*/

t_window		*gfx_window(t_gfx *gfx, int width, int height, char *title)
{
	t_window	*win;

	if ((win = (t_window *)ft_memalloc(sizeof(t_window))) == NULL)
		return (NULL);
	win->gfx = gfx;
	if ((win->ptr = mlx_new_window(gfx->mlx, width, height, title)) == NULL ||
			(win->title = ft_strdup(title)) == NULL ||
			(win->buf = gfx_image(gfx, width, height)) == NULL)
		return (gfx_free_window(win));
	win->id = get_window_id();
	win->width = width;
	win->height = height;
	ft_lstadd(&gfx->window, ft_lstnew(win, sizeof(t_window)));
	ft_memdel((void **)&win);
	win = ((t_window *)gfx->window->content);
	do_hooks(win);
	return (win);
}
