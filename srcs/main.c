/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:06:20 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/14 10:48:47 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

void			add_section(t_file *file, t_payload *payload);

# define CODE_SIZZ 132

int			main(int ac, char **av)
{
	t_file	file;

	ft_bzero(&file, sizeof(t_file));
	errno = -1;
	if (ac != 2 || check_file(av[1], &file) == EXIT_FAILURE)
		woody_error(&file);
	encrypt_code(&file);
	t_payload payload = {malloc(CODE_SIZZ), CODE_SIZZ, 0x60, 0x1e, 0x2a, 0x7c};
	ft_memcpy(payload.code, "\x50\x56\x57\x52\x51\x41\x50\x41\x51\xeb\x59\x5e\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\xba\x0e\x00\x00\x00\x0f\x05\xb9\x2b\x00\x00\x00\xbe\x08\x00\x00\x00\x48\x8d\x15\x09\x00\x00\x00\x4d\x31\xc0\x4d\x31\xc9\xeb\x41\x5f\x4a\x0f\xb6\x04\x07\x4c\x01\xc8\x48\x31\x02\x48\xff\xc2\x49\xff\xc0\x49\x39\xf0\x75\x07\x49\x83\xc1\x2a\x4d\x31\xc0\xe2\xe1\x41\x59\x41\x58\x59\x5a\x5f\x5e\x58\xe9\x26\x00\x00\x00\xe8\xa2\xff\xff\xff\x2e\x2e\x2e\x2e\x57\x4f\x4f\x44\x59\x2e\x2e\x2e\x2e\x0a\xe8\xba\xff\xff\xff\x20\x20\x20\x20\x20\x20\x20\x20", CODE_SIZZ);
	add_section(&file, &payload);
	ft_strdel(&payload.code);
	return (0);
}
