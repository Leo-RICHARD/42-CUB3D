/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:56:45 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 13:20:56 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcase(char *mode, char *str)
{
	if (!ft_strcmp(mode, "up"))
	{
		while (*str)
			if (*str > 96 && *str < 123)
				*(str++) -= 32;
	}
	else if (!ft_strcmp(mode, "low"))
	{
		while (*str)
			if (*str > 64 && *str < 91)
				*(str++) += 32;
	}
	return (str);
}
