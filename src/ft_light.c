/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:23:15 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/17 15:23:16 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_calc_light_init(t_m *m, int *size, t_rgb *rgb, t_irgb *c_int)
{
	*size = 0;
	*c_int = (t_irgb){0, 0, 0};
	*rgb = (t_rgb){0, 0, 0, 0};
	m->flags.shadow = 0;
}

void		ft_not_shadow(const t_m *m, const t_light *ptr, t_rgb *max)
{
	max->r = (UC)fmin(((m->phong.amb.r
		+ m->phong.dif.r
		+ m->phong.spc.r * m->rt.spc_int)
		* ptr->power), 255);
	max->g = (UC)fmin(((m->phong.amb.g
						+ m->phong.dif.g
						+ m->phong.spc.g * m->rt.spc_int)
						* ptr->power), 255);
	max->b = (UC)fmin(((m->phong.amb.b
						+ m->phong.dif.b
						+ m->phong.spc.b * m->rt.spc_int)
						* ptr->power), 255);
	max->opacity = 0;
}

void		ft_calc_shadow(const t_m *m, t_rgb *max)
{
	*max = m->phong.dif;
	*max = (t_rgb) {(UC)(max->r * SHADOW),
					(UC)(max->g * SHADOW),
					(UC)(max->b * SHADOW), 0};
}

void		ft_sum_light(t_m *m, t_light *ptr, t_irgb *c_int, t_rgb *max)
{
	m->flags.shadow = ft_shadow_ray(m, ptr);
	if (!m->flags.shadow)
		ft_not_shadow(m, ptr, max);
	else
		ft_calc_shadow(m, max);
	c_int->r += max->r;
	c_int->g += max->g;
	c_int->b += max->b;
}

t_rgb		ft_light_calc(t_m *m, t_rgb *color)
{
	int			size;
	t_light		*ptr;
	t_irgb		color_int;
	t_rgb		max;

	ptr = m->light;
	ft_calc_light_init(m, &size, &max, &color_int);
	while (ptr != NULL)
	{
		size++;
		m->phong = ft_phong(&m->rt, color, *ptr->o, m->cam);
		ft_sum_light(m, ptr, &color_int, &max);
		ptr = ptr->next;
	}
	if (size == 0)
	{
		m->phong = ft_phong(&m->rt, color, m->light_default, m->cam);
		return (m->phong.amb);
	}
	max.r = (UC)fmin(255, color_int.r);
	max.g = (UC)(int)fmin(255, color_int.g);
	max.b = (UC)fmin(255, color_int.b);
	return (max);
}
