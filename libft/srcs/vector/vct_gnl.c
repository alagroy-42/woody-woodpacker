/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:11:08 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/18 14:32:51 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_read_file(int fd, t_vector *vct)
{
	int		ret;
	char	buf[33];

	if (fd < 0 || fd > OPEN_MAX || read(fd, buf, 0) == -1)
		return (-1);
	while ((ret = read(fd, buf, 32)))
	{
		if (!ret)
			return (-1);
		buf[ret] = '\0';
		vct_strncat(vct, buf, ret);
	}
	return (ret);
}

int		vct_gnl(int fd, t_vector **vct)
{
	int		ret;
	char	buf[2];

	if (fd < 0 || fd > OPEN_MAX || read(fd, buf, 0) == -1)
		return (-1);
	vct_destroy(vct);
	*vct = vct_create(0);
	while ((ret = read(fd, buf, 1)))
	{
		if (ret == -1)
			return (ret);
		buf[ret] = '\0';
		if (buf[0] == '\n')
			return (ret);
		vct_append(*vct, buf[0]);
	}
	return (ret);
}
