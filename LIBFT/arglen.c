/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:54:01 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 15:51:32 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arglen(char type, int vard, unsigned int varx, char *vars)
{
	int	len;

	len = 1;
	if (type == 's')
		return (ft_strlen(vars));
	if (type == 'd' && vard < 0)
		len++;
	while (vard || varx)
	{
		vard /= 10;
		varx /= 16;
		len++;
	}
	return (len);
}
