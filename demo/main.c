/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 04:55:43 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 10:29:04 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"
#include "mlx.h"
#include "stdio.h"

static void	list_win(t_gfx *gfx)
{
	t_list *lst;
	t_window *win;

	lst = gfx->window;
	while (lst)
	{
		win = (t_window *)lst->content;
		printf("%d - %dx%d - %s\n", win->id, win->width, win->height, win->title);
		lst = lst->next;
	}
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_gfx *gfx;
	t_window *target;

	gfx = gfx_init();
	gfx_window(gfx, 100, 100, "hi");
	gfx_window(gfx, 140, 120, "hello");
	gfx_window(gfx, 200, 100, "morning");
	target = gfx_window(gfx, 100, 200, "heya");
	
	list_win(gfx);

	t_point p;
	t_point p1;

	p.x = 0;
	p.y = 0;
	p1.x = 100;
	p1.y = 121;
	gfx_line_window(target, p, p1, (t_color)0xFF0000);
	gfx_window_refresh(target);

	mlx_loop(gfx->mlx);
}
