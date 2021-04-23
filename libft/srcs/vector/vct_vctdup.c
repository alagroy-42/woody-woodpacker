/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_vctdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:22:27 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 18:02:07 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_vctdup(t_vector *vct)
{
	t_vector	*dup;

	if (!(dup = vct_create(vct->size)))
		return (NULL);
	vct_vctcpy(dup, vct);
	dup->len = vct->len;
	return (dup);
}
