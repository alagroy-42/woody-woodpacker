/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:51:39 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/12 15:31:20 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int rtrn;
	int neg;

	i = 0;
	rtrn = 0;
	neg = 0;
	while ((str[i] && str[i] < 14 && str[i] > 8) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		(str[i++] == '-') ? neg++ : neg;
	while (str[i] > 47 && str[i] < 58 && str[i])
		rtrn = 10 * rtrn + str[i++] - 48;
	return (neg ? -rtrn : rtrn);
}
