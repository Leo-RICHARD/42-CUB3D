/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:15:28 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 13:32:23 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	i3;

	i = -1;
	if (!*s2)
		return ((char *)s1);
	while (s1[++i] && i < len)
	{
		if (s1[i] == s2[0])
		{
			i3 = 1;
			while ((s2[i3] == s1[i + i3]) && s2[i3] != 0)
			{
				if (!(i + i3 < len))
					return (0);
				i3++;
			}
			if (s2[i3] == 0)
				return ((char *)(s1 + i));
		}
	}
	return (0);
}
