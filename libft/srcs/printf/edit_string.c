/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:22:32 by alagroy-          #+#    #+#             */
/*   Updated: 2019/07/16 09:35:18 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_insert_str(char *s, char *insert, int index)
{
	char	*rtrn;

	if (index > (int)ft_strlen(s))
		return (NULL);
	if (!(rtrn = (char *)malloc((ft_strlen(s) + ft_strlen(insert) + 1))))
		return (NULL);
	rtrn[ft_strlen(s) + ft_strlen(insert)] = '\0';
	ft_strncpy(rtrn, s, index);
	ft_strcat(rtrn, insert);
	ft_strcat(rtrn, s + index);
	free(s);
	free(insert);
	return (rtrn);
}

char	*ft_delete_flags(char *s, int index, int nb_char)
{
	char	*rtrn;
	char	*sub;
	char	*sub2;

	sub = ft_strsub(s, 0, index);
	sub2 = ft_strsub(s, index + nb_char, ft_strlen(s) - index - nb_char);
	if (!(rtrn = ft_strjoin(sub, sub2)))
		return (NULL);
	free(s);
	free(sub);
	free(sub2);
	return (rtrn);
}

char	*ft_double_percent(char *copy, char *flags)
{
	char	*rtrn;

	if (!(rtrn = (char *)malloc(sizeof(char) * (ft_strlen(copy)))))
		return (NULL);
	ft_strncpy(rtrn, copy, (size_t)(flags - copy));
	ft_strcat(rtrn, flags + 1);
	free(copy);
	return (rtrn);
}

int		ft_dprintf(int fd, const char *format, ...)
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
	write(fd, rtrn, len);
	free(rtrn);
	va_end(ap);
	return (len);
}
