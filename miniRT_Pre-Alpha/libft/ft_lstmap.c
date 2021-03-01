/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:37:01 by lignigno          #+#    #+#             */
/*   Updated: 2020/11/09 19:37:02 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	elem = start;
	lst = lst->next;
	while (lst != NULL && start != NULL)
	{
		elem->next = ft_lstnew(f(lst->content));
		if (elem == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		elem = elem->next;
		lst = lst->next;
	}
	return (start);
}
