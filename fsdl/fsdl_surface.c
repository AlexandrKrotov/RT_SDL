/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_surface.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:07:17 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:07:18 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

SDL_Surface	*fsdl_create_surface(int w, int h)
{
	SDL_Surface	*sf;

	if ((sf = SDL_CreateRGBSurface(0, w, h, 32, RM, GM, BM, AM)) == NULL)
	{
		SDL_Log("SDL_CreateRGBSurfaceWithFormat() failed: %s", SDL_GetError());
		exit(errno);
	}
	return (sf);
}

void		fsdl_surface_fill(SDL_Surface *s, SDL_Color c)
{
	SDL_FillRect(s, NULL, SDL_MapRGB(s->format, c.r, c.g, c.b));
}

void		fsdl_surface_px_alp(SDL_Surface *img, SDL_Color c, int x, int y)
{
	Uint32 *p;

	if (SDL_MUSTLOCK(img))
		SDL_LockSurface(img);
	p = (Uint32 *)img->pixels + y * img->pitch / img->format->BytesPerPixel + x;
	*p = SDL_MapRGBA(img->format, c.r, c.g, c.b, c.a);
	if (SDL_MUSTLOCK(img))
		SDL_UnlockSurface(img);
}

void		fsdl_surface_px(SDL_Surface *img, SDL_Color c, int x, int y)
{
	Uint32 *p;

	if (SDL_MUSTLOCK(img))
		SDL_LockSurface(img);
	p = (Uint32 *)img->pixels + y * img->pitch / img->format->BytesPerPixel + x;
	*p = SDL_MapRGB(img->format, c.r, c.g, c.b);
	if (SDL_MUSTLOCK(img))
		SDL_UnlockSurface(img);
}
