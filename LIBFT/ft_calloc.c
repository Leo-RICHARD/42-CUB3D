/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:27:50 by lrichard          #+#    #+#             */
/*   Updated: 2021/03/14 16:21:58 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*mem;

	mem = 0;
	len = nmemb * size;
	mem = (void *)malloc(sizeof(char) * len);
	if (mem)
		ft_bzero(mem, len);
	return (mem);
}
