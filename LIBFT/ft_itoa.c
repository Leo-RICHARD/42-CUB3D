/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:34:49 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 13:11:27 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				l;
	int				nn;
	unsigned int	nb;
	char			*nbr;

	l = 0;
	nn = n;
	while (++l && nn)
		nn /= 10;
	nb = n;
	if (n < 0 || (n > 0 && l-- && 1 == 3))
		nb = n * -1;
	if (!nmalloc((void **)&nbr, l + 1))
		return (NULL);
	nbr[l] = 0;
	while (l-- > 0)
	{
		nbr[l] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
