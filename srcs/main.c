/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:06:20 by alagroy-          #+#    #+#             */
/*   Updated: 2021/06/08 12:53:23 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static t_payload	get_payload(t_file *file)
{
	int			size;
	t_payload	payload;

	size = CODE_SIZE;
	if (file->arch == ELFCLASS64)
	{
		payload = (t_payload){malloc(size), size, 0x1e, 0x23, 0x2a, 0x78, 0x5c};
		ft_memcpy(payload.code, DECRYPTION_CODE, size);
		return (payload);
	}
	size = CODE_SIZE_32;
	payload = (t_payload){malloc(size), size, 0x16, 0x1b, 0x26, 0x67, 0x47};
	ft_memcpy(payload.code, DECRYPTION_CODE_32, size);
	return (payload);
}

int					main(int ac, char **av)
{
	t_file		file;
	t_payload	payload;

	ft_bzero(&file, sizeof(t_file));
	errno = 0;
	if (ac != 2 || check_file(av[1], &file) == EXIT_FAILURE)
		woody_error(&file, NULL, NULL, !errno ? ERROR_ARGS : ERROR_ERRNO);
	encrypt_code(&file);
	payload = get_payload(&file);
	inject(&file, &payload);
	ft_strdel(&payload.code);
	return (0);
}
