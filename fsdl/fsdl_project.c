/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:06:41 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:06:42 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

void			fsdl_project_exec(t_fvoid f, void *data)
{
	if (data == NULL)
		fsdl_init();
	TTF_Init();
	if (f != NULL)
		f();
	TTF_Quit();
	SDL_Quit();
}

void			fsdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("SDL could not init. SDL Err: %s\n", SDL_GetError());
		exit(errno);
	}
}

SDL_GLTXT	fsdl_glcontext_create(t_wnd *wnd)
{
	SDL_GLContext gl;

	if ((gl = SDL_GL_CreateContext(wnd->p)) == NULL)
		fsdl_errors_log(ERR_GL_CONTEXT);
	return (gl);
}
