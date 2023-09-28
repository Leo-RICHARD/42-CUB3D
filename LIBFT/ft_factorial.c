/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:28:25 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/02 16:46:23 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	long	ft_factorial(int n)
{
	int long	i;
	int long	nb;

	nb = n;
	i = nb;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (--i > 1)
		nb *= i;
	return (nb);
}
