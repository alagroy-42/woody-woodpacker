/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:57:32 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/29 12:04:43 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

void		woody_error(t_file *file)
{
	if (errno == -1)
	{
		ft_putendl_fd("woody_woodpacker: error: Wrong number of arguments.", 2);
		ft_putendl_fd("\tusage: ./woody_woodpacker filename", 2);
	}
	else
		perror("woody_woodpacker: error");
	if (file->ptr)
		munmap(file->ptr, file->size);
	if (file->fd)
		close(file->fd);
	exit(EXIT_FAILURE);
}
