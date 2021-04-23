/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:55:44 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 14:32:05 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_cat(t_vector *vct, t_vector *cat)
{
	unsigned int	i;

	if (vct->size < vct->len + cat->len)
	{
		vct->scale = vct->len + cat->len - vct->size;
		if (vct_realloc(vct) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < cat->len)
		vct->value[vct->len + i] = cat->value[i];
	vct->len += cat->len;
	return (EXIT_SUCCESS);
}

int		vct_strcat(t_vector *vct, char *str)
{
	unsigned int	i;
	size_t			strlen;

	if (!str)
		return (EXIT_SUCCESS);
	strlen = ft_strlen(str);
	if (vct->size < vct->len + strlen)
	{
		vct->scale = vct->len + strlen - vct->size;
		if (vct_realloc(vct) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < strlen)
		vct->value[i + vct->len] = str[i];
	vct->len += strlen;
	return (EXIT_SUCCESS);
}

int		vct_strncat(t_vector *vct, char *str, unsigned int n)
{
	unsigned int	i;

	if (!str)
		return (EXIT_SUCCESS);
	if (vct->size < vct->len + n)
	{
		vct->scale = vct->len + n - vct->size;
		if (vct_realloc(vct) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < n)
		vct->value[i + vct->len] = str[i];
	vct->len += n;
	return (EXIT_SUCCESS);
}
