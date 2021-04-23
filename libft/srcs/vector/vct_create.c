/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:31:02 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/17 18:51:53 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_create(int len)
{
	t_vector	*vct;

	if (!(vct = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(vct->value = ft_strnew(len)))
		return (NULL);
	ft_bzero(vct->value, len);
	vct->len = len;
	vct->scale = 0;
	vct->size = 0;
	return (vct);
}
