/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:11:35 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/19 20:53:36 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*rtrn;

	if (!(rtrn = ft_strnew(len)) || !(s))
		return (NULL);
	rtrn = ft_strncpy(rtrn, s + start, len);
	return (rtrn);
}
