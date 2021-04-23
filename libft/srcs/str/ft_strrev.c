/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:57:25 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/13 18:05:06 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		size;
	char	tmp;

	if (!s)
		return (NULL);
	size = ft_strlen(s) - 1;
	i = -1;
	while (++i <= size / 2)
	{
		tmp = s[i];
		s[i] = s[size - i];
		s[size - i] = tmp;
	}
	return (s);
}
