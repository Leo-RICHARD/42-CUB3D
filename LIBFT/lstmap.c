/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:29:42 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 15:01:36 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*nlist;
	t_list	*nbegin;

	list = lst;
	if (!list)
		return (NULL);
	nlist = lstnew(f(list->content));
	list = list->next;
	nbegin = nlist;
	while (list)
	{
		nlist->next = lstnew(f(list->content));
		if (!nlist->next)
			lstclear(&nbegin, del);
		list = list->next;
		nlist = nlist->next;
	}
	return (nbegin);
}
