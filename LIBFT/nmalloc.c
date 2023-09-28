/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:37:22 by lrichard          #+#    #+#             */
/*   Updated: 2021/06/23 16:37:22 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*nmalloc(void **var, int size)
{
	*var = malloc(sizeof(char) * size);
	if (!(*var))
		return (NULL);
	return (*var);
}

void	*nmallloc(void ***var, int size)
{
	*var = malloc(sizeof(char *) * size);
	if (!(*var))
		return (NULL);
	return (*var);
}
