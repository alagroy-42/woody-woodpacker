/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:13:18 by alagroy-          #+#    #+#             */
/*   Updated: 2019/02/13 18:04:57 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*rtrn;
	int		i;
	int		len;

	i = -1;
	if (!(rtrn = ft_strdup(format)))
		return (-1);
	va_start(ap, format);
	while (rtrn[++i])
		if (rtrn[i] == '%')
			rtrn = ft_fill_format(rtrn, rtrn + i, ap, &i);
	len = ft_strlen(rtrn);
	rtrn = ft_replace(rtrn, -1, 0);
	write(1, rtrn, len);
	free(rtrn);
	va_end(ap);
	return (len);
}

char	*ft_fill_format(char *copy, char *flags, va_list ap, int *index_flags)
{
	char	*rtrn;
	int		index;
	t_flags current;

	index = flags - copy;
	current = ft_init_flags();
	current = ft_fill_struct(flags, ap);
	*index_flags += ft_strlen(current.content) - 1;
	current = ft_find_nb_char(current);
	rtrn = ft_delete_flags(copy, index, current.nb_char);
	rtrn = ft_insert_str(rtrn, current.content, index);
	return (rtrn);
}

t_flags	ft_fill_struct(char *flags, va_list ap)
{
	int		i;
	t_flags	rtrn;

	i = 0;
	rtrn = ft_init_flags();
	while (flags[++i] && ft_isoption(flags[i]))
	{
		rtrn.hashtag += (flags[i] == '#') ? 1 : 0;
		rtrn.space += (flags[i] == ' ') ? 1 : 0;
		rtrn.plus += (flags[i] == '+') ? 1 : 0;
		rtrn.minus += (flags[i] == '-') ? 1 : 0;
		rtrn.zero += (flags[i] == '0') ? 1 : 0;
	}
	if (ft_isdigit(flags[i]) || flags[i] == '*')
	{
		rtrn.min_size = flags[i] == '*' ? va_arg(ap, int) : ft_atoi(flags + i);
		rtrn.wc += (flags[i] == '*');
		i += flags[i] == '*' ? 1 : ft_count_digit(rtrn.min_size);
	}
	if (flags[i] == '.')
	{
		rtrn.size_float = ft_atoi(flags + ++i);
		rtrn.size_float_status = ft_isdigit(flags[i]) ? 1 : 0;
	}
	return (ft_fill_convert(flags + i, rtrn, ap));
}

t_flags	ft_fill_convert(char *convert, t_flags rtrn, va_list ap)
{
	while (ft_isdigit(convert[0]))
		convert++;
	rtrn.convert = (convert[0] == 'h' && ft_strncmp(convert, "hh", 2)) ? h
		: rtrn.convert;
	rtrn.convert = (!ft_strncmp(convert, "hh", 2) && rtrn.convert == none) ? hh
		: rtrn.convert;
	rtrn.convert = (convert[0] == 'l' && rtrn.convert == none
			&& ft_strncmp(convert, "ll", 2)) ? l : rtrn.convert;
	rtrn.convert = (convert[0] == 'L' && rtrn.convert == none) ? L
		: rtrn.convert;
	rtrn.convert = (!ft_strncmp(convert, "ll", 2) && rtrn.convert == none) ? ll
		: rtrn.convert;
	return (rtrn = ft_fill_type(convert, rtrn, ap));
}

t_flags	ft_fill_type(char *flags, t_flags rtrn, va_list ap)
{
	int	i;

	i = 0;
	while (ft_isdigit(flags[i]) || ft_strchr("hlL", flags[i])
			|| flags[i] == '.')
		i++;
	if (ft_strchr("diouxXcspf", flags[i]))
		rtrn.type = flags[i];
	else if (flags[i] == '%')
	{
		rtrn.type = '%';
		rtrn.content = ft_strdup("%");
	}
	return (ft_fill_content(rtrn, ap));
}
