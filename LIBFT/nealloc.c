/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nealloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:21:01 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/28 17:39:06 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*nealloc(void **ptr, int size_supp)
{
	int		strl;
	char	*tptr;

	strl = ft_strlen(*(char **)ptr);
	tptr = (char *)malloc(sizeof(char) * (strl + size_supp));
	if (!tptr)
		return (0);
	if (*(char **)ptr && *(*(char **)ptr))
	{
		while (*(*(char **)ptr))
			*(tptr++) = *((*(char **)ptr)++);
		*tptr = 0;
	}
	free(*(char **)ptr - strl);
	*ptr = tptr - strl;
	return (*ptr);
}

void	*nealloc_abs(void **ptr, int size)
{
	int		strl;
	char	*tptr;

	strl = ft_strlen(*(char **)ptr);
	tptr = (char *)malloc(sizeof(char) * size);
	if (!tptr)
		return (0);
	tptr[0] = 0;
	if (*(char **)ptr && *(*(char **)ptr))
	{
		while (--size > strl)
			tptr[size] = 0;
		while (*(*(char **)ptr))
			*(tptr++) = *((*(char **)ptr)++);
		*tptr = 0;
	}
	free(*(char **)ptr - strl);
	*ptr = tptr - strl;
	return (*ptr);
}
