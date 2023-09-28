/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:57:09 by lrichard          #+#    #+#             */
/*   Updated: 2021/05/05 14:15:05 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convbase(char *input, char *ibase, char *obase)
{
	if (!ft_checkbase(ibase, ft_strlen(ibase))
		|| !ft_checkbase(obase, ft_strlen(obase)))
		return (0);
	return (itoa_base(atoi_base(input, ibase), obase));
}
