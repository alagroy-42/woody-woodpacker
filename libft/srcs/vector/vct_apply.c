/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:01:07 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/19 17:54:38 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vct_apply(t_vector *vct, t_func f)
{
	unsigned int	i;

	i = -1;
	while (++i < vct->len)
		vct->value[i] = f(vct->value[i]);
}
