/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strirchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:51:29 by alagroy-          #+#    #+#             */
/*   Updated: 2019/07/23 19:53:49 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strirchr(char *s, char c)
{
	char	*chr;

	chr = ft_strrchr(s, c);
	if (!chr)
		return (-1);
	return ((int)(chr - s));
}
