/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 00:55:58 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/12 17:05:05 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_cat;
	size_t	i;
	size_t	j;

	j = -1;
	i = ft_strlen(dst);
	size_cat = i + ft_strlen(src);
	if (size < i)
		return (size + ft_strlen(src));
	while (src[++j] && i + j < size - 1)
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (size_cat);
}
