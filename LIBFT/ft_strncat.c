/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:55:31 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 13:31:22 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dst, char *src, int len)
{
	char	*dest;

	dest = dst;
	if (dst && src)
	{
		while (*dst)
			dst++;
		while (*src && len--)
			*(dst++) = *(src++);
		if (*dst)
			*dst = 0;
	}
	return (dest);
}
