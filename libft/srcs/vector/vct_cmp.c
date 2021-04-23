/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:09:05 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 16:17:22 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_cmp(t_vector *vct, t_vector *cmp)
{
	unsigned int	i;

	i = -1;
	if (!vct->value || !cmp->value)
		return (EXIT_FAILURE);
	while (++i < vct->len && i < cmp->len)
		if (vct->value[i] != cmp->value[i])
			return (vct->value[i] - cmp->value[i]);
	return (vct->value[i] - cmp->value[i]);
}

int		vct_ncmp(t_vector *vct, t_vector *cmp, unsigned int n)
{
	unsigned int	i;

	i = -1;
	if (!vct->value || !cmp->value)
		return (EXIT_FAILURE);
	while (++i < vct->len && i < cmp->len && i < n)
		if (vct->value[i] != cmp->value[i])
			return (vct->value[i] - cmp->value[i]);
	return (0);
}
