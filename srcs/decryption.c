/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:54:16 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/18 14:23:49 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static void	*save_map(t_file *file, char *map, size_t map_size)
{
	void	*new_map;

	if (!(new_map = (void *)malloc(file->size + map_size + 1)))
		return (NULL);
	ft_memcpy(new_map, file->ptr, file->size);
	ft_memcpy(new_map + file->size, map, map_size);
	((char *)new_map)[file->size + map_size] = 0;
	return (new_map);
}

void		save_file(t_file *file, char *map, size_t map_size)
{
	int		fd;
	void	*saved_map;

	errno = 0;
	if (!(saved_map = save_map(file, map, map_size)))
		return ;
	if ((fd = open("woody.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0755)) == -1)
		return perror("open");
	if (syscall(SYS_rename, "woody.tmp", "woody"))
		return (perror("rename"));
	write(fd, saved_map, map_size + file->size);
	close(fd);
	syscall(SYS_unlink, "woody.tmp");
}
