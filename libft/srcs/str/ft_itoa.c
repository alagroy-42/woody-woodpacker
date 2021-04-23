/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:13:50 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/15 17:22:49 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		tmp;
	int		nb_digit;
	int		neg;
	char	*rtrn;

	nb_digit = 1;
	tmp = n;
	neg = (n < 0) ? 1 : 0;
	while (tmp / 10 != 0)
	{
		tmp /= 10;
		nb_digit++;
	}
	if (!(rtrn = (char *)malloc((nb_digit + neg + 1) * sizeof(char))))
		return (NULL);
	rtrn[nb_digit + neg] = '\0';
	nb_digit += neg;
	n = neg ? -n : n;
	while (--nb_digit >= neg)
	{
		rtrn[nb_digit] = n % 10 + 48;
		n /= 10;
	}
	neg ? rtrn[0] = '-' : 0;
	return ((rtrn[1] == '.') ? ft_strsub("-2147483648", 0, 11) : rtrn);
}
