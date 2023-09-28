/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:20:35 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 14:51:40 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(int vard)
{
	int	len;

	len = 0;
	if (vard <= 0)
		len++;
	while (vard)
	{
		vard /= 10;
		len++;
	}
	return (len);
}
