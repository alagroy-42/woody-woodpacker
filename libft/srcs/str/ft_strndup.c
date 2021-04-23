/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:39:53 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/15 17:27:51 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;

	if (n < ft_strlen(s1))
	{
		if (!(cpy = (char *)malloc((n + 1) * sizeof(char))))
			return (NULL);
		cpy = ft_strncpy(cpy, s1, n);
		cpy[n] = '\0';
	}
	else
		cpy = ft_strdup(s1);
	return (cpy);
}
