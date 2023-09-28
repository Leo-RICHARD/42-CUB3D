/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 22:20:21 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 14:26:53 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	i3;

	i = -1;
	if (!to_find[0])
		return (str);
	while (str[++i])
	{
		if (str[i] == to_find[0])
		{
			i3 = 1;
			while ((to_find[i3] == str[i + i3]) && to_find[i3] != 0)
				i3++;
			if (to_find[i3] == 0)
				return (str + i);
		}
	}
	return (0);
}
