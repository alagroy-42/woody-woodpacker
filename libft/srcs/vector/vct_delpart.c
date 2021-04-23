/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_delpart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:51:44 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/17 21:05:06 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_delpart(t_vector *vct, unsigned int i, unsigned int len)
{
	if (i > vct->len || i > vct->size)
		return (EXIT_FAILURE);
	if (i + len > vct->len)
	{
		ft_bzero(vct->value + i, vct->len - i);
		vct->len = i;
		return (EXIT_SUCCESS);
	}
	memmove(vct->value + i, vct->value + i + len, vct->len - i - len);
	vct->len -= len;
	return (EXIT_SUCCESS);
}
