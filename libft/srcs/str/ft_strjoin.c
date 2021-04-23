/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:38:06 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/15 17:27:13 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*rtrn;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	if (!(rtrn = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[++i])
		rtrn[i] = s1[i];
	while (s2[++j])
		rtrn[i + j] = s2[j];
	rtrn[i + j] = '\0';
	return (rtrn);
}
