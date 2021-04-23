/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_nl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:36:39 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/09 15:08:07 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		gnl_nl(int fd, char **line)
{
	char	*tmp;
	int		rtrn;

	rtrn = get_next_line(fd, line);
	tmp = *line;
	if (!(*line = ft_strjoin(*line, "\n")))
		rtrn = -1;
	ft_strdel(&tmp);
	return (rtrn);
}
