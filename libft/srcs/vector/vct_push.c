/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:09:58 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/19 18:12:23 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_push(t_vector *vct, char c)
{
	int		i;

	if (vct->len + 1 > vct->size)
	{
		vct->scale = 10;
		if (vct_realloc(vct))
			return (EXIT_FAILURE);
	}
	vct->len++;
	i = vct->len;
	while (--i > 0)
		vct->value[i] = vct->value[i - 1];
	vct->value[i] = c;
	return (EXIT_SUCCESS);
}

int		vct_npush(t_vector *vct, char c, unsigned int n)
{
	int		i;

	if (vct->len + n > vct->size)
	{
		vct->scale = n + vct->len - vct->size;
		if (vct_realloc(vct))
			return (EXIT_FAILURE);
	}
	vct->len += n;
	i = vct->len;
	while (--i >= (int)(n))
		vct->value[i] = vct->value[i - n];
	i = -1;
	while (++i < (int)n)
		vct->value[i] = c;
	return (EXIT_SUCCESS);
}

int		vct_strpush(t_vector *vct, char *str)
{
	size_t		strlen;
	t_vector	*dup;

	if (!(dup = vct_vctdup(vct)))
		return (EXIT_FAILURE);
	if (!str)
		return (EXIT_SUCCESS);
	strlen = ft_strlen(str);
	if (vct->len + strlen > vct->size)
	{
		vct->scale = vct->len + strlen - vct->size;
		if (vct_realloc(vct))
			return (EXIT_FAILURE);
	}
	vct_strcpy(vct, str);
	vct_cat(vct, dup);
	vct_destroy(&dup);
	return (EXIT_SUCCESS);
}
