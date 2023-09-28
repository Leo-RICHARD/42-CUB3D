/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:07:28 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 15:15:17 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printn(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	c = nb % 10 + 48;
	if (nb >= 10)
		printn(nb / 10);
	write(1, &c, 1);
}
