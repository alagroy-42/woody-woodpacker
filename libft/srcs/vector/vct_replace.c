/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:57:14 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 18:05:47 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vct_replace(t_vector *vct, char c, char replace)
{
	unsigned int	i;

	i = -1;
	while (++i < vct->len)
		if (vct->value[i] == c)
			vct->value[i] = replace;
}

int		vct_strreplace(t_vector *vct, char *s, char *replace)
{
	ssize_t	i;

	while ((i = vct_strstr(vct, s)) != -1)
	{
		vct_delpart(vct, i, ft_strlen(s));
		vct_insertstr(vct, replace, i);
	}
	return (EXIT_SUCCESS);
}
