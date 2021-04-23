/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_2dstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:22:06 by alagroy-          #+#    #+#             */
/*   Updated: 2019/06/07 15:04:14 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_expend_2dstr(char **tab, char *str)
{
	int		i;
	int		size;
	char	**new_tab;

	size = 0;
	i = -1;
	while (tab && tab[size])
		size++;
	if (!(new_tab = (char **)malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	while (++i < size)
		new_tab[i] = tab[i];
	new_tab[i] = ft_strdup(str);
	new_tab[i + 1] = NULL;
	free(tab);
	tab = NULL;
	return (new_tab);
}
