/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:42:28 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:42:30 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;

	if (!lst)
		return (0);
	final = ft_lstnew(f(lst->content));
	if (!final)
	{
		del(final);
		return (0);
	}
	lst = lst->next;
	while (lst)
	{
		if (!(f(lst->content)))
		{
			ft_lstclear(&final, del);
			return (0);
		}
		ft_lstadd_back(&final, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (final);
}
