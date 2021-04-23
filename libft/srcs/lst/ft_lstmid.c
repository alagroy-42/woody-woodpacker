/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:49:01 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/13 19:01:25 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmid(t_list *alst, t_list *new, size_t index)
{
	size_t	i;

	i = 0;
	if (!alst || !new || !index)
		return ;
	while (++i < index)
		alst->next = alst->next->next;
	new->next = alst->next;
	alst->next = new;
}
