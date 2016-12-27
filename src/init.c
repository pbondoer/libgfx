/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 05:33:42 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/27 23:08:42 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"

/*
** Destroys a gfx object
*/

t_gfx		*gfx_free(t_gfx *gfx)
{
	if (!gfx)
		return (NULL);
	ft_memdel((void **)&mlx);
	return (NULL);
}

/*
** Creates a new gfx object (should only be called once)
*/

t_mlx		*gfx_init(void)
{
	t_gfx	*gfx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL ||
			(gfx->mlx = mlx_init()) == NULL)
		return (NULL);
	return (mlx);
}
