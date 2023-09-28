/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:30:11 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 13:13:08 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_power(int nb, int power)
{
	unsigned long long	res;

	if (power < 0)
		return (0);
	res = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power-- > 1)
		res *= nb;
	return (res);
}
