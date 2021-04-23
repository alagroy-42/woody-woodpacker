/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:57:19 by alagroy-          #+#    #+#             */
/*   Updated: 2019/01/10 20:00:03 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_flags	ft_min_size(t_flags rtrn)
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
	rtrn.content = ft_strjoin(min_size, rtrn.content);
	free(tmp);
	free(min_size);
	return (rtrn);
}

t_flags	ft_join_precision(t_flags rtrn, int size)
{
	char	*new_content;
	int		i;

	i = -1;
	if (!(new_content = ft_strnew(size + ft_strlen(rtrn.content))))
		return (rtrn);
	while (++i < size)
		new_content[i] = '0';
	ft_strcat(new_content, rtrn.content);
	if (*rtrn.content == ' ' || *rtrn.content == '-' || *rtrn.content == '+')
	{
		new_content[0] = rtrn.content[0];
		new_content[size] = '0';
	}
	ft_strdel(&rtrn.content);
	rtrn.content = new_content;
	return (rtrn);
}

t_flags	ft_precision(t_flags rtrn)
{
	int		size;

	if (!rtrn.content || !ft_strchr("diouxXf", rtrn.type))
		return (rtrn);
	size = rtrn.size_float - ft_strlen(rtrn.content);
	if (*rtrn.content == ' ' || *rtrn.content == '-' || *rtrn.content == '+')
		size++;
	if (size < 1)
		return (rtrn);
	return (ft_join_precision(rtrn, size));
}
