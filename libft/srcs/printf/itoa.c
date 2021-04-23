/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:24:16 by alagroy-          #+#    #+#             */
/*   Updated: 2019/01/14 14:44:45 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

char	*ft_itoa_max(long long nb)
{
	int					nb_digit;
	long long			tmp;
	unsigned long long	nb2;
	int					neg;
	char				*rtrn;

	neg = (nb < 0) ? 1 : 0;
	tmp = nb;
	nb_digit = neg ? 2 : 1;
	while (tmp /= 10)
		nb_digit++;
	if (!(rtrn = (char *)malloc((nb_digit + 1) * sizeof(char))))
		return (NULL);
	rtrn[nb_digit] = '\0';
	if (neg)
		rtrn[0] = '-';
	nb2 = neg ? nb * -1 : nb;
	while (--nb_digit >= neg)
	{
		rtrn[nb_digit] = nb2 % 10 + '0';
		nb2 /= 10;
	}
	return (rtrn);
}

char	*ft_itoa_unsigned_max(unsigned long long nb)
{
	int					nb_digit;
	unsigned long long	tmp;
	char				*rtrn;

	tmp = nb;
	nb_digit = 1;
	while (tmp /= 10)
		nb_digit++;
	if (!(rtrn = (char *)malloc((nb_digit + 1) * sizeof(char))))
		return (NULL);
	rtrn[nb_digit] = '\0';
	while (--nb_digit >= 0)
	{
		rtrn[nb_digit] = nb % 10 + '0';
		nb /= 10;
	}
	return (rtrn);
}

char	*ft_itoa_base(unsigned long long nb, int base)
{
	int					nb_digit;
	unsigned long long	tmp;
	char				*rtrn;

	tmp = nb;
	nb_digit = 1;
	while (tmp /= base)
		nb_digit++;
	if (!(rtrn = (char *)malloc((nb_digit + 1) * sizeof(char))))
		return (NULL);
	rtrn[nb_digit] = '\0';
	while (--nb_digit >= 0)
	{
		rtrn[nb_digit] = (nb % base < 10) ? nb % base + '0' :
			nb % base + 'A' - 10;
		nb /= base;
	}
	return (rtrn);
}

char	*ft_itoa_base_lowcase(unsigned long long nb, int base)
{
	int					nb_digit;
	unsigned long long	tmp;
	char				*rtrn;

	tmp = nb;
	nb_digit = 1;
	while (tmp /= base)
		nb_digit++;
	if (!(rtrn = (char *)malloc((nb_digit + 1) * sizeof(char))))
		return (NULL);
	rtrn[nb_digit] = '\0';
	while (--nb_digit >= 0)
	{
		rtrn[nb_digit] = (nb % base < 10) ? nb % base + '0' :
			nb % base + 'a' - 10;
		nb /= base;
	}
	return (rtrn);
}

char	*ft_itoa_float(long double nb, t_flags rtrn)
{
	char		*ret;
	long double	tmp;
	int			i;

	i = 1;
	tmp = nb * ft_power(10, rtrn.size_float);
	if (tmp - (long long)tmp >= 0.5)
		tmp++;
	ret = ft_itoa_max(tmp);
	if (!nb || ret[0] == '0')
	{
		if (!rtrn.size_float)
			return (ft_strdup("0"));
		free(ret);
		ret = ft_strnew(rtrn.size_float + 2);
		ret[0] = '0';
		ret[1] = '.';
		while (++i < rtrn.size_float + 2)
			ret[i] = '0';
		return (ret);
	}
	if (rtrn.size_float)
		ret = ft_insert_str(ret, ft_strdup("."),
				ft_strlen(ret) - rtrn.size_float);
	return (ret);
}
