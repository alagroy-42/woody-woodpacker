/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:53:57 by alagroy-          #+#    #+#             */
/*   Updated: 2019/01/10 20:07:05 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_fill_string(char *str, t_flags rtrn)
{
	if (!str)
	{
		if (rtrn.size_float && !rtrn.size_float_status)
			return (ft_strdup("(null)"));
		else
			return (ft_strndup("(null)", rtrn.size_float));
	}
	if (!rtrn.size_float_status && rtrn.size_float)
		return (ft_strdup(str));
	else
		return (ft_strndup(str, rtrn.size_float));
}

int		ft_count_digit(int nb)
{
	int count;

	count = 1;
	while (nb /= 10)
		count++;
	return (count);
}
