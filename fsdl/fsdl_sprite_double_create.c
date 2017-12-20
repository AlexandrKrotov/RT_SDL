/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_sprite_2_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:32:48 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:32:49 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

t_sprd	*fsdl_sprite_dbl_create_heap(t_tex *tex, SDL_Rect *src)
{
	t_sprd	*sprite;

	if ((sprite = malloc(sizeof(t_sprd))) == NULL)
		ft_errors_general(ERR_MALLOC);
	sprite->tex = tex;
	if (src == NULL)
		sprite->src = fsdl_rect_set(0, 0, tex->w, tex->h);
	else
		sprite->src = *src;
	return (sprite);
}

t_sprd	*fsdl_sprite_dbl_create_from_file(SDL_Renderer *r, const char *fn)
{
	t_sprd	*sprite;
	t_tex	*texture;

	texture = fsdl_texture_from_image_heap(r, fn);
	sprite = fsdl_sprite_dbl_create_heap(texture, NULL);
	return (sprite);
}

void	fsdl_spr_dbl_to_point(t_wnd *w, t_sprd *spr, t_v2d pos, t_v2d sc)
{
	t_drect		dr;
	SDL_Rect	r;
	double		ax;
	double		ay;

	ax = spr->sx * sc.x * spr->tex->w;
	ay = spr->sy * sc.y * spr->tex->h;
	dr.x = (w->wid * pos.x - ax / 2.);
	dr.y = (w->hei * pos.y - ay / 2.);
	dr.w = ax;
	dr.h = ay;
	r = fsdl_rect_dbl_to_int(dr);
	SDL_RenderCopy(spr->tex->r, spr->tex->t, &spr->src, &r);
}

void	fsdl_sprite_dbl_and_texture_free(t_sprd *spr)
{
	fsdl_texture_free_heap(spr->tex);
	free(spr);
}
