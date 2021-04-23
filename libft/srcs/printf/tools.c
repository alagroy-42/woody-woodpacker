/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:28:19 by alagroy-          #+#    #+#             */
/*   Updated: 2019/02/13 18:00:06 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_flags	ft_init_flags(void)
{
	t_flags	rtrn;

	rtrn.hashtag = 0;
	rtrn.space = 0;
	rtrn.wc = 0;
	rtrn.plus = 0;
	rtrn.minus = 0;
	rtrn.zero = 0;
	rtrn.min_size = 0;
	rtrn.size_float = 6;
	rtrn.size_float_status = 0;
	rtrn.convert = none;
	rtrn.type = '\0';
	rtrn.nb_char = 0;
	rtrn.content = NULL;
	return (rtrn);
}

int		ft_power(int nb, int pow)
{
	int ret;

	ret = nb;
	if (pow == 0)
		return (1);
	if (pow)
		while (--pow > 0)
			ret *= nb;
	return (ret);
}

int		ft_isoption(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == ' ' || c == '0')
		return (1);
	return (0);
}

char	*ft_ctoa(char c)
{
	char	*rtrn;

	if (!(rtrn = (char *)malloc(2 * sizeof(char))))
		return (NULL);
	rtrn[0] = !c ? -1 : c;
	rtrn[1] = '\0';
	return (rtrn);
}

char	*ft_replace(char *str, char before, char after)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == before)
			str[i] = after;
	}
	return (str);
}
