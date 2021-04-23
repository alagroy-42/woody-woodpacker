/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:51:46 by alagroy-          #+#    #+#             */
/*   Updated: 2019/02/13 18:13:40 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

t_flags	ft_fill_content(t_flags rtrn, va_list ap)
{
	unsigned long long arg;

	if (ft_strchr("ouxX", rtrn.type))
	{
		if (rtrn.convert == h)
			arg = (unsigned short)va_arg(ap, unsigned int);
		else if (rtrn.convert == hh)
			arg = (unsigned char)va_arg(ap, unsigned int);
		else if (rtrn.convert == l)
			arg = va_arg(ap, unsigned long);
		else if (rtrn.convert == ll)
			arg = va_arg(ap, unsigned long long);
		else
			arg = (unsigned int)va_arg(ap, unsigned int);
		if (rtrn.type == 'o')
			rtrn.content = ft_itoa_base(arg, 8);
		else if (rtrn.type == 'u')
			rtrn.content = ft_itoa_unsigned_max(arg);
		else if (rtrn.type == 'x')
			rtrn.content = ft_itoa_base_lowcase(arg, 16);
		else if (rtrn.type == 'X')
			rtrn.content = ft_itoa_base(arg, 16);
	}
	rtrn = ft_fill_content2(rtrn, ap);
	return (rtrn);
}

t_flags	ft_fill_content2(t_flags rtrn, va_list ap)
{
	long long	arg;
	char		*args;

	if (ft_strchr("di", rtrn.type))
	{
		(rtrn.convert == h) ? arg = (short int)va_arg(ap, int) : 0;
		(rtrn.convert == hh) ? arg = (signed char)va_arg(ap, int) : 0;
		if (rtrn.convert == l)
			arg = va_arg(ap, long);
		else if (rtrn.convert == ll)
			arg = va_arg(ap, long long);
		else if (rtrn.convert == none)
			arg = va_arg(ap, int);
		rtrn.content = ft_itoa_max(arg);
	}
	if (rtrn.type == 's')
	{
		args = va_arg(ap, char *);
		rtrn.content = ft_fill_string(args, rtrn);
	}
	rtrn = ft_fill_content3(rtrn, ap);
	rtrn = ft_fill_options(rtrn);
	return (rtrn);
}

t_flags	ft_fill_content3(t_flags rtrn, va_list ap)
{
	char		argc;
	long		argp;
	long double	argf;
	char		*f;

	if (ft_strchr("cp", rtrn.type))
	{
		rtrn.type == 'c' ? argc = (char)va_arg(ap, int) : 0;
		rtrn.type == 'p' ? argp = va_arg(ap, long) : 0;
		rtrn.type == 'c' ? rtrn.content = ft_ctoa(argc) : 0;
		if (rtrn.type == 'p')
		{
			f = ft_itoa_base_lowcase(argp, 16);
			rtrn.content = ft_strjoin("0x", f);
			free(f);
		}
	}
	else if (rtrn.type == 'f')
	{
		argf = rtrn.convert == none || rtrn.convert == l ? va_arg(ap, double)
		: va_arg(ap, long double);
		rtrn.content = ft_itoa_float(argf, rtrn);
	}
	return (rtrn);
}

t_flags	ft_find_nb_char(t_flags rtrn)
{
	char	*numbers;

	rtrn.nb_char = 1;
	rtrn.nb_char += rtrn.hashtag;
	rtrn.nb_char += rtrn.space;
	rtrn.nb_char += rtrn.plus;
	rtrn.nb_char += rtrn.minus;
	rtrn.nb_char += rtrn.zero;
	rtrn.nb_char += rtrn.wc;
	numbers = ft_itoa(rtrn.min_size);
	rtrn.nb_char += (numbers[0] == '0' || rtrn.wc) ? 0 : ft_strlen(numbers);
	rtrn.nb_char += (rtrn.type) ? 1 : 0;
	ft_strdel(&numbers);
	numbers = rtrn.size_float_status ? ft_itoa(rtrn.size_float) : 0;
	rtrn.nb_char += (numbers == NULL) ? 0 : ft_strlen(numbers);
	ft_strdel(&numbers);
	rtrn.nb_char += rtrn.size_float_status;
	rtrn.nb_char += !rtrn.size_float_status && !rtrn.size_float ? 1 : 0;
	rtrn.nb_char += (rtrn.convert == h) ? 1 : 0;
	rtrn.nb_char += (rtrn.convert == hh) ? 2 : 0;
	rtrn.nb_char += (rtrn.convert == l) ? 1 : 0;
	rtrn.nb_char += (rtrn.convert == ll) ? 2 : 0;
	rtrn.nb_char += (rtrn.convert == L) ? 1 : 0;
	return (rtrn);
}

t_flags	ft_fill_options(t_flags rtrn)
{
	char	*tmp;

	tmp = rtrn.content;
	if (rtrn.size_float <= 0 && ft_strchr("diouxX", rtrn.type)
			&& rtrn.content[0] == '0')
	{
		rtrn.content = ft_strnew(0);
		ft_strdel(&tmp);
	}
	if (rtrn.space)
		rtrn = ft_space(rtrn);
	if (rtrn.plus)
		rtrn = ft_plus(rtrn);
	if (rtrn.size_float_status)
		rtrn = ft_precision(rtrn);
	if (rtrn.zero && !rtrn.minus && !(ft_strchr("diouxX", rtrn.type)
		&& (rtrn.size_float_status || !rtrn.size_float)))
		rtrn = ft_zero(rtrn);
	if (rtrn.hashtag)
		rtrn = ft_hashtag(rtrn);
	if (rtrn.minus)
		rtrn = ft_minus(rtrn);
	else
		rtrn = ft_min_size(rtrn);
	return (rtrn);
}
