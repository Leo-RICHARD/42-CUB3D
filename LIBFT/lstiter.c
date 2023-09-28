/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:41:01 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 14:59:58 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*list;

	list = lst;
	while (list && f)
	{
		f(list->content);
		list = list->next;
	}
}
