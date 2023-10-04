/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:45:22 by atucci            #+#    #+#             */
/*   Updated: 2023/01/30 14:50:19 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ely;

	if (lst == NULL)
		return (0);
	new_lst = 0;
	while (lst != NULL)
	{
		ely = ft_lstnew(f(lst->content));
		if (ely == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, ely);
		lst = lst->next;
	}
	return (new_lst);
}
