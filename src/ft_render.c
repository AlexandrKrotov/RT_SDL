/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 16:10:45 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/20 17:05:38 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_primary_ray(t_m *m, int x, int y)
{
	t_vertex	cam;
	t_objs		*ptr;
	t_ray		ray;
	int			inter;

	cam = m->cam;
	cam.z += m->trans.zoom;
	cam.x += m->trans.shift;
	ptr = m->scene;
	ray.o = (t_vertex){x + m->trans.shift, y, 0 + m->trans.zoom};
	ray.d = ft_sub_vec(ray.o, cam);
	ray.d = ft_normalized_vector(ray.d);
	ray = (t_ray){cam, ray.d};
	m->rt.t = 200000;
	inter = FALSE;
	while (ptr != NULL)
	{
		if (ptr->ft_inter(&m->rt, &ray, ptr))
		{
			ptr->ft_info(&m->rt, &ray, ptr);
			inter = TRUE;
		}
		ptr = ptr->next;
	}
	return (inter);
}

int			ft_shadow_ray(t_m *m, t_light *light)
{
	t_objs		*ptr;
	t_ray		ray;
	t_vertex	dir;
	t_vertex	orig;
	int			shadow;

	shadow = FALSE;
	ptr = m->scene;
	orig = m->rt.inter;
	dir = ft_sub_vec(*light->o, orig);
	m->rt.t = ft_get_magnitude(dir);
	dir = ft_normalized_vector(dir);
	ray = (t_ray){orig, dir};
	while (ptr != NULL)
	{
		if (ptr->ft_inter(&m->rt, &ray, ptr))
		{
			shadow = TRUE;
			break ;
		}
		ptr = ptr->next;
	}
	return (shadow);
}

void		ft_draw(t_m *m)
{
	int			x;
	int			y;
	int			inter;
	SDL_Color	color;

	y = m->dsp.rend_hs;
	while (y < m->dsp.rend_he)
	{
		x = m->dsp.rend_ws;
		while (x < m->dsp.rend_we)
		{
			m->x = x;
			m->y = y;
			m->rt.rgb = (SDL_Color){0, 0, 0, 0};
			m->rt.n = 0;
			inter = ft_primary_ray(m, x, y);
			color = m->rt.rgb;
			if (inter == TRUE)
				color = ft_light_calc(m, &color);
			fsdl_surface_px_alp(m->surf, color, x + m->dsp.half_w, y + m->dsp.half_h);
			x++;
		}
		y++;
	}
}

int			ft_render(t_m *m)
{
	if (m->flags.redraw == TRUE)
	{
		m->surf = fsdl_create_surface(D_WIDTH, D_HEIGHT);
		ft_draw(m);
		SDL_Texture *texture;
		texture	= SDL_CreateTextureFromSurface(m->lprm->wnd->r, m->surf);
		SDL_FreeSurface(m->surf);
		if (texture == NULL) {
			fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
			exit(1);
		}
		SDL_RenderCopy(m->lprm->wnd->r, texture, NULL, NULL);
		SDL_RenderPresent(m->lprm->wnd->r);
//		if (m->flags.aliasing == TRUE)
//			ft_blur(m->mlx->img.gda, BLUR);
		m->flags.redraw = FALSE;
	}
	return (0);
}
