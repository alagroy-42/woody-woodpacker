/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:01:15 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/12 15:41:45 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtrn;
	int		i;

	if (!(s))
		return (NULL);
	i = -1;
	if (!(rtrn = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		rtrn[i] = f(i, s[i]);
	return (rtrn);
}
