/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_strstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:06:14 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 16:28:47 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

ssize_t	vct_strstr(t_vector *vct, char *s)
{
	unsigned int	i;
	unsigned int	j;
	t_vector		*vct_str;

	if (!s)
		return (EXIT_FAILURE);
	if (!(vct_str = vct_strdup(s)))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < vct->len)
	{
		j = 0;
		while (j < vct->len && j < vct_str->len
				&& vct->value[i + j] == vct_str->value[j])
			j++;
		if (j == vct_str->len)
		{
			vct_destroy(&vct_str);
			return (i);
		}
	}
	vct_destroy(&vct_str);
	return (-1);
}
