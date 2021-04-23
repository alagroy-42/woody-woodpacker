/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:36:09 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/17 18:44:04 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_strdup(char *str)
{
	t_vector	*vct;

	if (!(vct = vct_create(0)))
		return (NULL);
	if (!str)
		return (vct);
	if (!(vct->value = ft_strnew(ft_strlen(str))))
		return (vct);
	vct->len = ft_strlen(str);
	vct->size = ft_strlen(str);
	ft_strcpy(vct->value, str);
	vct->value[vct->len] = '\0';
	return (vct);
}
