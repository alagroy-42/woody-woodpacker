/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:54:16 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/12 13:35:30 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

void		save_file(t_file *file, char *map, size_t map_size)
{
	int		fd;

	errno = 0;
	if ((fd = open("woody", O_WRONLY | O_CREAT | O_TRUNC, 0755)) == -1)
		return ;
	write(fd, file->ptr, file->size);
	write(fd, map, map_size);
	close(fd);
}
