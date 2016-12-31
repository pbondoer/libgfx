/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 05:33:42 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 05:30:24 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "libgfx.h"

/*
** Destroys a gfx object
*/

t_gfx		*gfx_free(t_gfx *gfx)
{
	if (!gfx)
		return (NULL);
	ft_memdel((void **)&gfx);
	return (NULL);
}

/*
** Creates a new gfx object (should only be called once)
*/

t_gfx		*gfx_init(void)
{
	t_gfx	*gfx;

	if ((gfx = ft_memalloc(sizeof(t_gfx))) == NULL ||
			(gfx->mlx = mlx_init()) == NULL)
		return (NULL);
	return (gfx);
}
