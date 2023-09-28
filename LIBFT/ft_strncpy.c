/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:13:50 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 13:32:07 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dst, char *src, int len)
{
	char	*dest;

	dest = dst;
	if (dst && src)
	{
		while (*src && len--)
			*(dst++) = *(src++);
		if (*dst)
			*dst = 0;
	}
	return (dest);
}
