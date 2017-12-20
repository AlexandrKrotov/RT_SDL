/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_window_manage_prm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:33:34 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:33:35 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

void	fsdl_window_get_dim(t_wnd *w)
{
	SDL_GetWindowSize(w->p, &w->wid, &w->hei);
}

void	fsdl_window_set_title(t_wnd *wnd)
{
	SDL_SetWindowTitle(wnd->p, wnd->name);
}

void	fsdl_window_set_minimum_size(t_wnd *w, int min_w, int min_h)
{
	SDL_SetWindowMinimumSize(w->p, min_w, min_h);
}
