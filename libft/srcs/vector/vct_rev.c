/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:54:38 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 15:58:47 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vct_rev(t_vector *vct)
{
	unsigned int	i;
	char			c;

	i = -1;
	while (++i < vct->len / 2)
	{
		c = vct->value[vct->len - 1 - i];
		vct->value[vct->len - 1 - i] = vct->value[i];
		vct->value[i] = c;
	}
}
