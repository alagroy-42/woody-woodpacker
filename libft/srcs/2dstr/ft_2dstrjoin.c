/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:21:03 by alagroy-          #+#    #+#             */
/*   Updated: 2019/07/16 11:47:48 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_2dstrjoin(char **tab1, char **tab2)
{
	char	**new_tab;
	int		i;
	int		j;
	int		len;

	len = ft_2dstrlen(tab1) + ft_2dstrlen(tab2);
	if (!(new_tab = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	i = -1;
	j = -1;
	while (tab1 && tab1[++i])
		new_tab[++j] = tab1[i];
	i = -1;
	while (tab2 && tab2[++i])
		new_tab[++j] = tab2[i];
	new_tab[len] = NULL;
	free(tab1);
	free(tab2);
	return (new_tab);
}
