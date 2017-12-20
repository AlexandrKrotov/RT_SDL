/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_sprite_1_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:22:10 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:22:14 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

t_spri	fsdl_sprite_int_create_stack(t_tex *tex, SDL_Rect spr)
{
	t_spri	sprite;

	sprite.tex = tex;
	sprite.src = spr;
	return (sprite);
}

t_spri	*fsdl_sprite_int_create_heap(t_tex *tex, SDL_Rect *src)
{
	t_spri	*sprite;

	if ((sprite = malloc(sizeof(t_spri))) == NULL)
		ft_errors_general(ERR_MALLOC);
	sprite->tex = tex;
	if (src == NULL)
		sprite->src = fsdl_rect_set(0, 0, tex->w, tex->h);
	else
		sprite->src = *src;
	return (sprite);
}

t_spri	*fsdl_sprite_int_create_from_file(SDL_Renderer *r, const char *fn)
{
	t_spri	*sprite;
	t_tex	*texture;

	texture = fsdl_texture_from_image_heap(r, fn);
	sprite = fsdl_sprite_int_create_heap(texture, NULL);
	return (sprite);
}

void	fsdl_sprite_int_and_texture_free(t_spri *spr)
{
	fsdl_texture_free_heap(spr->tex);
	free(spr);
}
