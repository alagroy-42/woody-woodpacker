/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:14:00 by alagroy-          #+#    #+#             */
/*   Updated: 2021/02/26 12:41:39 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstsort(t_list *alst, int (*cmp)(t_list *, t_list *))
{
	t_list	*tmp;
	size_t	i;
	size_t	lstsize;
	void	*tmp_content;

	i = -1;
	lstsize = ft_lstsize(alst);
	while (++i < lstsize)
	{
		tmp = alst;
		while (tmp)
		{
			if (tmp->next && cmp(tmp, tmp->next))
			{
				tmp_content = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = tmp_content;
			}
			tmp = tmp->next;
		}
	}
}
