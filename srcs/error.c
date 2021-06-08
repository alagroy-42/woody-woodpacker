/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:57:32 by alagroy-          #+#    #+#             */
/*   Updated: 2021/06/08 13:48:44 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static char	*g_error_messages[] =\
{
	"",
	"program headers extends past the end of the file.",
	"text segment extends past the end of the file.",
	"Wrong number of arguments.\n\tusage: ./woody_woodpacker filename",
};

static void	print_error_message(int code)
{
	int		size;

	size = sizeof(g_error_messages) / sizeof(char *);
	if (code > 0 && code < size)
		dprintf(2, "woody_woodpacker: error: %s\n", g_error_messages[code]);
}

void		woody_error(t_file *file, t_payload *payload, t_woody *woody,
				int code)
{
	if (code != ERROR_ERRNO)
		print_error_message(code);
	else
		perror("woody_woodpacker: error");
	if (file->ptr)
		munmap(file->ptr, file->size);
	if (file->fd)
		close(file->fd);
	if (payload)
		ft_strdel(&payload->code);
	if (woody)
		free(woody->ptr);
	exit(EXIT_FAILURE);
}
