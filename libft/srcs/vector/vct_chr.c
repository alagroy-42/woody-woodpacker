/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:36:52 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 15:45:09 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

ssize_t		vct_chr(t_vector *vct, char c)
{
	unsigned int	i;

	i = -1;
	while (++i < vct->len)
		if (vct->value[i] == c)
			return (i);
	return (-1);
}

ssize_t		vct_rchr(t_vector *vct, char c)
{
	int	i;

	i = vct->len + 1;
	while (--i > -1)
		if (vct->value[i] == c)
			return (i);
	return (-1);
}
