/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:38:49 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:38:51 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errors.h"

void	ft_errors_general(int err)
{
	if (err == ERR_MALLOC)
		perror("Error: Malloc cannot allocate memory.\n");
	else if (err == ERR_NO_FILE)
		perror("Error: No such file.\n");
	else if (err == ERR_DIV_ZERO)
		ft_errors_custom("Error: Division by zero!\n");
	else if (err == ERR_NULL_PTR)
		ft_errors_custom("Error: Trying to make something to NULL ptr!\n");
	else if (err == ERR_GET_LINE)
		ft_errors_custom("Error: Cannot get next line.\n");
	exit(0);
}

void	ft_errors_custom(const char *str_err)
{
	printf("%s\n", str_err);
	exit(0);
}

void	ft_errors_warning(const char *str_err)
{
	printf("%s\n", str_err);
}
