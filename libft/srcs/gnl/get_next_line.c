/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharrie <pcharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:12:14 by alagroy-          #+#    #+#             */
/*   Updated: 2019/07/01 16:09:02 by pcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_end(char *read)
{
	free(read);
	return (0);
}

char	*ft_read(const int fd, int *ret)
{
	char	buf[BUFF_SIZE + 1];
	char	*join;
	char	*tmp;

	if (!(join = ft_strnew(0)))
		return (NULL);
	while ((*ret = read(fd, buf, BUFF_SIZE)))
	{
		if (*ret == -1)
			return (NULL);
		buf[*ret] = '\0';
		tmp = join;
		if (!(join = ft_strjoin(join, buf)))
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
		if (ft_strchr(join, '\n'))
			break ;
	}
	return (join);
}

int		ft_line(const int fd, char **line, char **stock_buf)
{
	int		ret;
	char	*nl_ptr;
	char	*tmp;
	char	*read;

	if (!(read = ft_read(fd, &ret)))
		return (-1);
	if (!*stock_buf)
		*stock_buf = ft_strnew(0);
	tmp = read;
	read = ft_strjoin(*stock_buf, read);
	free(tmp);
	if (!read)
		return (-1);
	if (read[0] == '\0' && ret == 0)
		return (ft_end(read));
	nl_ptr = ft_strchr(read, '\n');
	*line = nl_ptr ? ft_strsub(read, 0, nl_ptr - read) : ft_strdup(read);
	tmp = *stock_buf;
	*stock_buf = nl_ptr ? ft_strdup(nl_ptr + 1) : NULL;
	free(tmp);
	free(read);
	if (!*line || !stock_buf)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*stock_buf[5000];
	char		*nl_ptr;
	char		*tmp;

	if (fd < 0 || fd > 5000 || !line || read(fd, stock_buf[fd], 0) == -1 ||
			BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (!stock_buf[fd] || !(nl_ptr = ft_strchr(stock_buf[fd], '\n')))
		return (ft_line(fd, line, &stock_buf[fd]));
	else
	{
		*line = ft_strsub(stock_buf[fd], 0, (size_t)(nl_ptr - stock_buf[fd]));
		tmp = stock_buf[fd];
		stock_buf[fd] = ft_strdup(nl_ptr + 1);
		free(tmp);
		return (stock_buf[fd] ? 1 : -1);
	}
	return (-1);
}
