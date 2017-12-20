/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:01:47 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:01:48 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# include <stdlib.h>
//TODO KIll print
# include <stdio.h>

# define ERR_MALLOC 555
# define ERR_NO_FILE 556
# define ERR_NULL_PTR 557
# define ERR_GET_LINE 558
# define ERR_DIV_ZERO 666

void	ft_errors_general(int err);
void	ft_errors_custom(const char *str_err);
void	ft_errors_warning(const char *str_err);

#endif
