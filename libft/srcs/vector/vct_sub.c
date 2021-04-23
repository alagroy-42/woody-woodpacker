/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:01:02 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 16:05:35 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_sub(t_vector *vct, int i, int len)
{
	t_vector	*sub;

	if (len == 0)
		return (NULL);
	if (!(sub = vct_create(len)))
		return (NULL);
	vct_strncpy(sub, vct->value + i, len);
	return (sub);
}
