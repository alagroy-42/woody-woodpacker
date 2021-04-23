/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:06:44 by alagroy-          #+#    #+#             */
/*   Updated: 2019/02/13 17:50:26 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>

typedef enum	e_convert
{
	none,
	h,
	hh,
	l,
	L,
	ll,
}				t_convert;

typedef struct	s_flags
{
	int			wc;
	int			hashtag;
	int			space;
	int			plus;
	int			minus;
	int			zero;
	int			min_size;
	int			size_float;
	int			size_float_status;
	t_convert	convert;
	char		type;
	int			nb_char;
	char		*content;
}				t_flags;

int				ft_printf(const char *format, ...);
char			*ft_itoa_base(unsigned long long nb, int base);
char			*ft_itoa_base_lowcase(unsigned long long nb, int base);
char			*ft_itoa_max(long long nb);
char			*ft_itoa_unsigned_max(unsigned long long nb);
char			*ft_itoa_float(long double nb, t_flags rtrn);
char			*ft_insert_str(char *s, char *insert, int index);
char			*ft_delete_flags(char *s, int index, int nb_char);
char			*ft_double_percent(char *copy, char *flags);
char			*ft_fill_format(char *copy, char *flags, va_list ap, int *i);
int				ft_power(int nb, int pow);
int				ft_isoption(char c);
int				ft_count_digit(int nb);
char			*ft_ctoa(char c);
char			*ft_replace(char *str, char before, char after);
char			*ft_fill_string(char *str, t_flags rtrn);
t_flags			ft_precision(t_flags rtrn);
t_flags			ft_hashtag(t_flags rtrn);
t_flags			ft_space(t_flags rtrn);
t_flags			ft_plus(t_flags rtrn);
t_flags			ft_minus(t_flags rtrn);
t_flags			ft_zero(t_flags rtrn);
t_flags			ft_min_size(t_flags rtrn);
t_flags			ft_fill_options(t_flags rtrn);
t_flags			ft_fill_struct(char *flags, va_list ap);
t_flags			ft_fill_convert(char *convert, t_flags rtrn, va_list ap);
t_flags			ft_init_flags(void);
t_flags			ft_fill_type(char *flags, t_flags rtrn, va_list ap);
t_flags			ft_fill_content(t_flags rtrn, va_list ap);
t_flags			ft_fill_content2(t_flags rtrn, va_list ap);
t_flags			ft_fill_content3(t_flags rtrn, va_list ap);
t_flags			ft_find_nb_char(t_flags rtrn);
int				ft_dprintf(int fd, const char *format, ...);

#endif
