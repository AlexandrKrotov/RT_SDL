/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:22:53 by akrotov           #+#    #+#             */
/*   Updated: 2017/09/20 17:30:26 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_key_hook(int key, t_m *m)
{
	if (key == ESC)
		ft_exit();
	m->flags.redraw = TRUE;
	if (key == B)
		m->flags.aliasing = m->flags.aliasing == FALSE ? TRUE : FALSE;
	return (1);
}
