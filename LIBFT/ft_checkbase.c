/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:01:46 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/02 16:44:03 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkbase(char *base, int blen)
{
	int	i;
	int	i3;

	i = -1;
	if (!blen)
		return (0);
	while (++i < blen)
	{
		i3 = -1;
		while (base[++i3] && i3 < blen)
		{
			if (i3 != i && base[i3] == base[i])
				return (0);
			if (base[i3] == 45 || base[i3] == 43)
				return (0);
			if (base[i3] == 32 || (base[i3] > 8 && base[i3] < 14))
				return (0);
		}
	}
	return (1);
}
