/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_np.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:08:09 by lrichard          #+#    #+#             */
/*   Updated: 2021/04/11 14:08:19 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(unsigned char a, char *base)
{
	int		n;
	char	c;

	c = a % 16;
	n = c;
	if (a >= 16)
		ft_print(a / 16, base);
	write(1, &base[n], 1);
}

void	prints_np(char *str)
{
	int		i;
	char	*hx;

	i = -1;
	hx = "0123456789abcdef\0";
	while (str[++i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			if ((unsigned char)str[i] < 16)
				write(1, "0", 1);
			ft_print((unsigned char)str[i], hx);
		}
		else
			write(1, &str[i], 1);
	}
}
