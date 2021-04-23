/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:05:42 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 17:23:00 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_realloc(t_vector *vct)
{
	char	*old_value;

	old_value = vct->value;
	if (!(vct->value = ft_strnew(vct->size + vct->scale + 1)))
	{
		vct->value = old_value;
		return (EXIT_FAILURE);
	}
	vct->size = vct->size + vct->scale;
	vct->scale = 0;
	ft_strcpy(vct->value, old_value);
	ft_strdel(&old_value);
	return (EXIT_SUCCESS);
}
