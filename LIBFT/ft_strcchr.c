/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:00:30 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 13:21:45 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcchr(char *str, char c, int occ)
{
	int	o;

	o = 1;
	while (*str)
		if (*(str++) == c && o++ == occ)
			return (str - 1);
	return (str);
}
