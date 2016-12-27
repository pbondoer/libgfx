/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libglx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:35:18 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/28 00:25:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

# include <stdint.h>

/*
** A basic two dimensional integer vector
*/
typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

/*
** Easier memory access to color components
*/

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

/*
** Holds a generic mlx image with associated metadata
*/

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
	int			width;
	int			height;
}					t_image;

/*
** Holds a single window with associated metadata
*/

typedef struct		s_window
{
	int			id;
	void		*ptr;
	int			width;
	int			height;
	char		*title;
	t_image		*buf;
}					t_window;

/*
** Holds one instance of gfx, which controls windows
*/

typedef struct		s_gfx
{
	void		*mlx;
	t_list		*window;
}					t_gfx;

/*
** Core functions: intialize and destroy the main gfx instance
*/

t_gfx				*gfx_init(void);
t_gfx				*gfx_free(t_gfx *gfx);

/*
** Window functions: used internally when creating windows
*/

t_window			*gfx_window(t_gfx *gfx, int width, int height, char *title);
t_window			*gfx_free_window(t_gfx *gfx, t_window *win);

/*
** Images: these can be used to manipulate images
*/

t_image				*gfx_image(t_gfx *gfx, int width, int height);
t_image				*gfx_free_image(t_gfx *gfx, t_image *img);
t_color				gfx_image_get_pixel(t_image *image, int x, int y);
void				gfx_image_set_pixel(t_image *img, int x, int y, t_color c);
void				gfx_image_clear(t_image *image);

/*
** Color helpers
*/

t_color				clerp(t_color c1, t_color c2, float p);
t_color				cilerp(int c1, int c2, float p);
#endif
