/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:19:27 by alagroy-          #+#    #+#             */
/*   Updated: 2021/02/25 13:10:53 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2dstrdel(char ***array)
{
	int	i;

	if (!array || !*array)
		return ;
	i = -1;
	while ((*array)[++i])
		free((*array)[i]);
	free(*array);
	*array = NULL;
}
