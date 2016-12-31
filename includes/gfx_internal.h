/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 07:50:22 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/31 08:05:02 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** These are internal functions used by GFX
*/

#ifndef GFX_INTERNAL_H
# define GFX_INTERNAL_H

# include "libgfx.h"

int		gfx_window_hook_expose(t_window *win);
int		gfx_window_hook_close(t_window *win);
#endif
