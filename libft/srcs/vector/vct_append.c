/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:12:36 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/19 17:22:38 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_append(t_vector *vct, char c)
{
	if (vct->len + 1 > vct->size)
	{
		vct->scale = 10;
		if (vct_realloc(vct) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	vct->value[vct->len] = c;
	vct->len++;
	return (EXIT_SUCCESS);
}

int		vct_nappend(t_vector *vct, char c, int n)
{
	int		i;

	if (vct->len + n > vct->size)
	{
		vct->scale = vct->len + n - vct->size;
		if (vct_realloc(vct) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < n)
		vct->value[vct->len + i] = c;
	vct->len += n;
	return (EXIT_SUCCESS);
}
