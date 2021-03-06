/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 14:43:24 by pbondoer          #+#    #+#             */
/*   Updated: 2017/02/03 03:56:49 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"
#include "libft.h"

/*
** Smoothly interpolated between two color values (useful for alpha blending
** and gradients!)
*/

t_color			clerp(const t_color c1, const t_color c2, float p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1);
	p = ft_clamp(p, 0.0f, 1.0f);
	if (p == 0.0f)
		return (c1);
	if (p == 1.0f)
		return (c2);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

/*
** Same as above, but converts ints as a lazy shortcut to casting
*/

inline t_color	cilerp(const int c1, const int c2, const float p)
{
	if (c1 == c2)
		return ((t_color)c1);
	return (clerp((t_color)c1, (t_color)c2, p));
}
