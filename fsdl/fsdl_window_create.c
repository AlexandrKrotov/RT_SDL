/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_window_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:38:54 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:08:09 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

t_wnd	*fsdl_window_create_stuct(int wid, int hei, const char *name)
{
	t_wnd	*wnd;

	if ((wnd = malloc(sizeof(t_wnd))) == NULL)
		ft_errors_general(ERR_MALLOC);
	fsdl_window_set_prm(wnd, wid, hei, name);
	return (wnd);
}

void	fsdl_window_set_prm(t_wnd *wnd, int wid, int hei, const char *name)
{
	wnd->wid = wid;
	wnd->hei = hei;
	wnd->name = name;
}

void	fsdl_window_create(t_wnd *wnd)
{
	wnd->p = SDL_CreateWindow(wnd->name, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, wnd->wid, wnd->hei, SDL_WINDOW_OPENGL
	| SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	if (wnd->p == NULL)
		fsdl_errors_log(ERR_WND_CRE);
	wnd->r = SDL_CreateRenderer(wnd->p, -1, SDL_REND);
}

void	fsdl_window_and_renderer_create(t_wnd *wnd)
{
	if (SDL_CreateWindowAndRenderer(wnd->wid, wnd->hei,
	SDL_WINDOW_RESIZABLE, &wnd->p, &wnd->r) == -1)
		fsdl_errors_log(ERR_WND_REND_CRE);
}
