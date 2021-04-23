/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:10:29 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/15 17:30:28 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*rtrn;

	i = -1;
	if (!(rtrn = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (++i < (int)size + 1)
		rtrn[i] = '\0';
	return (rtrn);
}
