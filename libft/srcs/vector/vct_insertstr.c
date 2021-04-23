/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_insertstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:26:39 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 17:53:53 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_insertstr(t_vector *vct, char *str, int index)
{
	t_vector	*beg;
	t_vector	*end;

	if (!str)
		return (EXIT_SUCCESS);
	if (index == 0)
		return (vct_strpush(vct, str));
	if (vct->len + ft_strlen(str) > vct->size)
	{
		vct->scale = vct->len + ft_strlen(str) - vct->size;
		if (vct_realloc(vct))
			return (EXIT_FAILURE);
	}
	if (!(beg = vct_sub(vct, 0, index)))
		return (EXIT_FAILURE);
	if (!(end = vct_sub(vct, index, vct->len - index)))
		vct_destroy(&beg);
	if (!end)
		return (EXIT_FAILURE);
	vct_vctcpy(vct, beg);
	vct_strcat(vct, str);
	vct_cat(vct, end);
	return (EXIT_SUCCESS);
}
