/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_error_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:05:35 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:05:37 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

void	fsdl_errors_log(int err)
{
	if (err == ERR_TEX_QUERY)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't get texture size: %s", SDL_GetError());
	if (err == ERR_TEX_CREATE)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't load texture: %s", SDL_GetError());
	if (err == ERR_WND_REND_CRE)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't create window and renderer: %s", SDL_GetError());
	if (err == ERR_WND_CRE)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't create window: %s", SDL_GetError());
	if (err == ERR_GL_CONTEXT)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't create GL context: %s", SDL_GetError());
	if (err == ERR_FILE_OPEN)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't open file: %s", SDL_GetError());
	if (err == ERR_FILE_READ)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"Couldn't read file: %s", SDL_GetError());
	exit(0);
}
