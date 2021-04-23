/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:45:42 by alagroy-          #+#    #+#             */
/*   Updated: 2019/05/24 11:56:24 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_strlist(t_list *begin)
{
	t_list	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (tmp->content)
			ft_putendl(tmp->content);
		else
			ft_putendl("(null)");
		tmp = tmp->next;
	}
}
