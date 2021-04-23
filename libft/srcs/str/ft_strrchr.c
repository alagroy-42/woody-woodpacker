/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:19:12 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/07 17:26:41 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rtrn;

	i = -1;
	rtrn = NULL;
	while (s[++i])
		if (s[i] == c)
			rtrn = (char *)s + i;
	if (s[i] == c)
		rtrn = (char *)s + i;
	return (rtrn);
}
