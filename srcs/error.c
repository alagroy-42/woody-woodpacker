/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:57:32 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/26 14:13:28 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static char	*g_error_tab[] =\
{
	"wrong number of arguments.\n\tusage : ./woody_woodpacker filename",
	"cannot open file, check that it exists with the right permissions.",
	"memory error, cannot map file into memory",
	"wrong format or architecture, please submit a valid ELF file.",
	"not an executable file",
};

void		woody_error(int error, t_file *file)
{
	ft_putstr_fd("error : ", 2);
	ft_putendl_fd(g_error_tab[error], 2);
	if (file->ptr)
		munmap(file->ptr, file->size);
	if (file->fd)
		close(file->fd);
	exit(EXIT_FAILURE);
}
