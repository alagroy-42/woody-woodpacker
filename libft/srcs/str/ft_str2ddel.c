/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2ddel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:46:48 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/17 15:52:47 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str2ddel(char **tab, int index)
{
	int	i;

	i = index;
	ft_strdel(tab + i);
	while (tab[++i])
		tab[i - 1] = tab[i];
	tab[i - 1] = tab[i];
}
