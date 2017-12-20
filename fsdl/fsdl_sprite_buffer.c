/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_sprite_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:07:09 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:07:10 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

t_spribf	*fsdl_spr_buffer_create(t_tex *tex, SDL_Rect *rect_arr, int sz)
{
	t_spribf	*spr_buff;
	int		i;

	if ((spr_buff = malloc(sizeof(t_spribf))) == NULL)
		ft_errors_general(ERR_MALLOC);
	spr_buff->sz = sz;
	spr_buff->tex = tex;
	if ((spr_buff->s_arr = malloc(sizeof(t_spri) * sz)) == NULL)
		ft_errors_general(ERR_MALLOC);
	i = 0;
	while (i < sz)
	{
		spr_buff->s_arr[i] = fsdl_sprite_int_create_heap(tex, &rect_arr[i]);
		i++;
	}
	return (spr_buff);
}

void	fsdl_spr_buffer_free(t_spribf *buf)
{
	int	i;

	fsdl_texture_free_heap(buf->tex);
	i = 0;
	while (i < buf->sz)
	{
		free(buf->s_arr[i]);
		i++;
	}
	free(buf->s_arr);
	free(buf);
}
