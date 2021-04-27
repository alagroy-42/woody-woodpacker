/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:47:57 by alagroy-          #+#    #+#             */
/*   Updated: 2019/07/23 19:54:00 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strichr(char *s, char c)
{
	char	*chr;

	chr = ft_strchr(s, c);
	if (!chr)
		return (-1);
	return ((int)(chr - s));
}