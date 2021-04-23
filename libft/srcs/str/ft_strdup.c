/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:39:53 by alagroy-          #+#    #+#             */
/*   Updated: 2019/02/15 19:13:56 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*cpy;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	if (!(cpy = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	cpy = ft_strcpy(cpy, s1);
	cpy[size] = '\0';
	return (cpy);
}
