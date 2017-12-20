/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:15:41 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 15:15:42 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_scene(t_m *all)
{
	all->scene = malloc(sizeof(t_objs));
	all->scene->obj = NULL;
	all->scene->ft_inter = NULL;
	all->scene->ft_info = NULL;
	all->scene->next = NULL;
}

void	ft_init_light(t_m *all)
{
	all->light = malloc(sizeof(t_vertex));
	all->light->o = NULL;
	all->light->next = NULL;
}

void	init_all(t_m *m)
{
	m->mlx = mmoc(sizeof(t_mlx));
	m->mlx->mlx = mlx_init();
	m->mlx->wnd = mlx_new_window(m->mlx->mlx, D_WIDTH, D_HEIGHT, D_NAME);
	m->dsp.dsp_w = D_WIDTH;
	m->dsp.dsp_h = D_HEIGHT;
	m->dsp.half_h = m->dsp.dsp_h / 2;
	m->dsp.half_w = m->dsp.dsp_w / 2;
	m->dsp.rend_hs = -m->dsp.half_h;
	m->dsp.rend_he = m->dsp.half_h;
	m->dsp.rend_ws = -m->dsp.half_w;
	m->dsp.rend_we = m->dsp.half_w;
	m->cam = (t_vertex){0, 0, -1000};
	m->light_default = m->cam;
	m->light = NULL;
	m->trans.zoom = 0;
	m->trans.shift = 0;
	m->rt.rgb = (t_rgb){0, 0, 0, 0};
	m->rt.norm = (t_vertex){0, 0, 0};
	m->flags.redraw = TRUE;
	m->flags.aliasing = FALSE;
	ft_init_scene(m);
	ft_init_light(m);
}
