/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rect_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:06:48 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:06:49 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

SDL_Rect	fsdl_rect_set_relative(SDL_Rect r, t_p pos, int wid, int hei)
{
	r.x = pos.x + r.x;
	r.y = pos.y + r.y;
	r.w = wid;
	r.h = hei;
	return (r);
}

t_drect		fsdl_rect_spr_dest_rel(t_spri *spr, t_drect sr)
{
	t_drect	r;

	r.x = spr->dest.x + spr->dest.w * sr.x / 100;
	r.y = spr->dest.y + spr->dest.h * sr.y / 100;
	r.w = spr->dest.w * sr.w / 100;
	r.h = spr->dest.h * sr.h / 100;
	return (r);
}

SDL_Rect	fsdl_rect_wndrel(t_wnd *w, t_drect wr)
{
	SDL_Rect	r;
	int			st_x;
	int			st_y;

	st_x = (int)(w->wid * wr.x / 100);
	st_y = (int)(w->hei * wr.y / 100);
	r.x = st_x;
	r.y = st_y;
	r.w = (int)(w->wid * wr.w / 100);
	r.h = (int)(w->hei * wr.h / 100);
	return (r);
}
