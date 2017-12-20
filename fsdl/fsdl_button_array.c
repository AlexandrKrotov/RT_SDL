/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_button_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:05:22 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:05:24 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

t_btn	**fsdl_btn_create_2d_array(size_t row, size_t col)
{
	t_btn	**arr;
	size_t	i;

	i = 1;
	if ((arr = malloc(sizeof(t_btn *) * row)) == NULL)
		ft_errors_general(ERR_MALLOC);
	if ((arr[0] = malloc(sizeof(t_btn) * row * col)) == NULL)
		ft_errors_general(ERR_MALLOC);
	while (i != row)
	{
		arr[i] = arr[i - 1] + col;
		i++;
	}
	return (arr);
}
