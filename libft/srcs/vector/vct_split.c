/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:45:52 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 16:29:41 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_split(t_vector *vct, char c)
{
	ssize_t		i;
	t_vector	*rtrn;

	i = vct_chr(vct, c);
	if (i == -1)
		return (NULL);
	if (!(rtrn = vct_sub(vct, 0, i)))
		return (NULL);
	vct_delpart(vct, 0, i + 1);
	return (rtrn);
}

t_vector	*vct_strsplit(t_vector *vct, char *str)
{
	ssize_t		i;
	t_vector	*rtrn;

	i = vct_strstr(vct, str);
	ft_printf("i = %d\n", i);
	if (i == -1)
		return (NULL);
	if (!(rtrn = vct_sub(vct, 0, i)))
		return (NULL);
	vct_delpart(vct, 0, i + ft_strlen(str));
	return (rtrn);
}
