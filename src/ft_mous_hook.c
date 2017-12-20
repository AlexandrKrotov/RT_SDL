/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mous_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:46:47 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/20 17:31:35 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_mouse_cord(int x, int y, t_m *m)
{
	m->x = x;
	m->y = y;
	return (y);
}

int		ft_mouse_hook(int key, int x, int y, t_m *m)
{
	x = y;
	y = x;
	key = 0;
	m->flags.redraw = TRUE;
	return (y);
}
