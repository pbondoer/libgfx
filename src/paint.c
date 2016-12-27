/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 23:14:46 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/27 23:15:28 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libgfx.h"

/*
** Clears an image to black pixels / empty data
*/

void		gfx_image_clear(t_image *image)
{
	ft_bzero(image->ptr, image->width * image->height * image->bpp);
}