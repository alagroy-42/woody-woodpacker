/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <pcharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:05:50 by pcharrie          #+#    #+#             */
/*   Updated: 2019/07/22 20:05:58 by pcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrjoin(char *s1, char *s2, char *s3)
{
	char *tmp;
	char *str;

	if (!(tmp = ft_strjoin(s1, s2)))
		return (NULL);
	str = ft_strjoin(tmp, s3);
	free(tmp);
	return (str);
}
