/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:01:37 by alagroy-          #+#    #+#             */
/*   Updated: 2019/01/10 19:39:52 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

t_flags	ft_hashtag(t_flags rtrn)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = rtrn.content;
	if (rtrn.type == 'o' && rtrn.content[0] != '0')
		rtrn.content = ft_strjoin("0", rtrn.content);
	else if (rtrn.type == 'x' || rtrn.type == 'X')
	{
		while (rtrn.content[++i])
			if (rtrn.content[i] != '0')
			{
				i = -1;
				while (++i < 2 && rtrn.zero)
					if (rtrn.content[i] == '0')
						rtrn.content = ft_delete_flags(rtrn.content, 0, 1);
					else
						break ;
				rtrn.content = rtrn.type == 'x' ? ft_strjoin("0x", rtrn.content)
					: ft_strjoin("0X", rtrn.content);
				break ;
			}
	}
	rtrn.content != tmp ? free(tmp) : 0;
	return (rtrn);
}

t_flags	ft_space(t_flags rtrn)
{
	char	*tmp;

	tmp = rtrn.content;
	if (ft_strchr("dif", rtrn.type) && rtrn.content[0] != '-' && !rtrn.plus)
	{
		rtrn.content = ft_strjoin(" ", rtrn.content);
		free(tmp);
	}
	return (rtrn);
}

t_flags	ft_plus(t_flags rtrn)
{
	char	*tmp;

	tmp = rtrn.content;
	if (ft_strchr("dif", rtrn.type) && rtrn.content[0] != '-')
	{
		rtrn.content = ft_strjoin("+", rtrn.content);
		free(tmp);
	}
	return (rtrn);
}

t_flags	ft_minus(t_flags rtrn)
{
	int		i;
	char	*min_size;
	char	*tmp;
	int		size;

	size = rtrn.min_size - ft_strlen(rtrn.content);
	i = -1;
	if (size < 0)
		return (rtrn);
	min_size = ft_strnew(size);
	while (++i < size)
		min_size[i] = ' ';
	tmp = rtrn.content;
	rtrn.content = ft_strjoin(rtrn.content, min_size);
	free(tmp);
	free(min_size);
	return (rtrn);
}

t_flags	ft_zero(t_flags rtrn)
{
	int		i;
	char	*zero;
	char	*tmp;
	int		size;

	size = rtrn.min_size - ft_strlen(rtrn.content);
	i = -1;
	if (size <= 0)
		return (rtrn);
	if (!(zero = ft_strnew(size)))
		return (rtrn);
	while (++i < size)
		zero[i] = '0';
	if (*rtrn.content == ' ' || *rtrn.content == '-' || *rtrn.content == '+')
	{
		zero[0] = rtrn.content[0];
		rtrn.content[0] = '0';
	}
	tmp = rtrn.content;
	rtrn.content = ft_strjoin(zero, rtrn.content);
	free(tmp);
	free(zero);
	return (rtrn);
}
