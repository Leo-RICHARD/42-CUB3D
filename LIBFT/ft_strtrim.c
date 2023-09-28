/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:57:24 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 14:28:52 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_contains(char *set, char c)
{
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

static char	*ft_append(const char *s, char *nstr, size_t nlen)
{
	int	i;

	i = 0;
	nstr[nlen] = 0;
	while (nlen--)
	{
		nstr[i] = s[i];
		i++;
	}
	return (nstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	nlen;
	char	*nstr;

	nlen = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_contains((char *)set, *s1))
		s1++;
	nlen = ft_strlen(s1);
	if (*s1)
		nlen--;
	while (s1[nlen] && ft_contains((char *)set, s1[nlen]))
		nlen--;
	if (*s1)
		nlen++;
	nstr = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!nstr)
		return (NULL);
	return (ft_append(s1, nstr, nlen));
}
