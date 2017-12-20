/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rect_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:18:45 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:19:11 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

SDL_Rect	fsdl_rect_set(int x, int y, int wid, int hei)
{
	SDL_Rect r;

	r.x = x;
	r.y = y;
	r.w = wid;
	r.h = hei;
	return (r);
}

t_drect		fsdl_rect_double(double x, double y, double wid, double hei)
{
	t_drect r;

	r.x = x;
	r.y = y;
	r.w = wid;
	r.h = hei;
	return (r);
}

SDL_Rect	fsdl_rect_dbl_to_int(t_drect d)
{
	SDL_Rect	r;

	r.x = (int)d.x;
	r.y = (int)d.y;
	r.w = (int)d.w;
	r.h = (int)d.h;
	return (r);
}

t_drect		fsdl_rect_int_to_d(SDL_Rect r)
{
	t_drect	d;

	d.x = (double)r.x;
	d.y = (double)r.y;
	d.w = (double)r.w;
	d.h = (double)r.h;
	return (d);
}
