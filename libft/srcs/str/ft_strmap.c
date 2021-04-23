/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:52:38 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/15 17:27:32 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rtrn;
	int		i;

	if (!(s))
		return (NULL);
	i = -1;
	if (!(rtrn = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		rtrn[i] = f(s[i]);
	return (rtrn);
}
