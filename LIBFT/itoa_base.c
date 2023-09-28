/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:35:53 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 14:57:44 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*itoa_base(int n, char *base)
{
	int				l;
	int				blen;
	int				nn;
	unsigned int	nb;
	char			*nbr;

	l = 0;
	nn = n;
	blen = ft_strlen(base);
	while (++l && nn)
		nn /= blen;
	nb = n;
	if (n < 0 || (n > 0 && --l && 1 == 3))
		nb = -n;
	if (!nmalloc((void **)&nbr, l + 1))
		return (NULL);
	nbr[l] = 0;
	while (l-- > 0)
	{
		nbr[l] = base[nb % blen];
		nb /= blen;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
