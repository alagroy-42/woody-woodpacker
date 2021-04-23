/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:28:37 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/13 18:40:14 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	elem = ft_lstnew((const void *)f(lst)->content, f(lst)->content_size);
	lst = lst->next;
	begin = elem;
	while (lst)
	{
		elem->next = ft_lstnew((const void *)f(lst)->content,
				f(lst)->content_size);
		elem = elem->next;
		lst = lst->next;
	}
	return (begin);
}
