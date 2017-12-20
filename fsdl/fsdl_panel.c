/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_panel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:06:31 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:06:33 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

t_panel	*fsdl_panel_create_empty(SDL_Rect pos, int wid, int hei)
{
	t_panel	*p;

	if ((p = malloc(sizeof(t_panel))) == NULL)
		ft_errors_general(ERR_MALLOC);
	p->pos = pos;
	p->sz = wid * hei;
	return (p);
}

t_btn	*fsdl_panel_mouse_check(t_panel *p, t_p pos)
{
	int	i;

	i = 0;
	while (i < p->sz)
	{
		if (fsdl_btn_mouse_over_check(pos.x, pos.y, &p->arr[0][i]) == 1)
			return (&p->arr[0][i]);
		i++;
	}
	return (NULL);
}

void	fsdl_panel_show_all_btn(t_panel *p)
{
	int	i;

	i = 0;
	while (i < p->sz)
	{
		fsdl_btn_show(&p->arr[0][i], &p->arr[0][i].dest);
		i++;
	}
}

void	fsdl_panel_free_btn_free(t_panel *p, int btn_num)
{
	int i;

	i = 0;
	while (i < btn_num)
	{
		if (p->arr[i]->spr[0] != NULL)
			fsdl_sprite_int_and_texture_free(p->arr[i]->spr[0]);
		if (p->arr[i]->spr[1] != NULL)
			fsdl_sprite_int_and_texture_free(p->arr[i]->spr[1]);
		i++;
	}
	free(p->arr[0]);
	free(p->arr);
	free(p);
}
