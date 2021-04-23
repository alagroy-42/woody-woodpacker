/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_strcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:47:31 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 18:05:35 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_vctncpy(t_vector *vct, t_vector *cpy, unsigned int n)
{
	unsigned int	i;

	if (!vct->value || !cpy->value)
		return (EXIT_FAILURE);
	if (n > vct->size)
	{
		vct->scale = n - vct->size;
		if (vct_realloc(vct))
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < cpy->len && i < n)
		vct->value[i] = cpy->value[i];
	vct->len = n;
	return (EXIT_SUCCESS);
}

int		vct_vctcpy(t_vector *vct, t_vector *cpy)
{
	unsigned int	i;

	if (!vct->value || !cpy->value)
		return (EXIT_FAILURE);
	if (cpy->len > vct->size)
	{
		vct->scale = cpy->len - vct->size;
		if (vct_realloc(vct))
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < cpy->len)
		vct->value[i] = cpy->value[i];
	vct->len = cpy->len;
	return (EXIT_SUCCESS);
}

int		vct_strcpy(t_vector *vct, char *str)
{
	size_t			strlen;
	unsigned int	i;

	if (!str)
		return (EXIT_SUCCESS);
	strlen = ft_strlen(str);
	if (vct->size < strlen)
	{
		vct->scale = strlen - vct->size;
		if (vct_realloc(vct) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < strlen)
		vct->value[i] = str[i];
	vct->len = strlen;
	return (EXIT_SUCCESS);
}

int		vct_strncpy(t_vector *vct, char *str, unsigned int n)
{
	size_t			strlen;
	unsigned int	i;

	if (!str)
		return (EXIT_SUCCESS);
	strlen = ft_strlen(str);
	if (strlen > n)
		strlen = n;
	if (vct->size < strlen)
	{
		vct->scale = strlen - vct->size;
		if (vct_realloc(vct) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < strlen)
		vct->value[i] = str[i];
	vct->len = strlen;
	return (EXIT_SUCCESS);
}
