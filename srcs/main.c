/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:06:20 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/12 15:46:18 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

void			add_section(t_file *file, t_payload *payload);

# define CODE_SIZZ 52

int			main(int ac, char **av)
{
	t_file	file;

	ft_bzero(&file, sizeof(t_file));
	errno = -1;
	if (ac != 2 || check_file(av[1], &file) == EXIT_FAILURE)
		woody_error(&file);
	// encrypt_code(&file);
	t_payload payload = {malloc(CODE_SIZZ), CODE_SIZZ, 0x1d};
	ft_memcpy(payload.code, "\x50\x56\x57\x52\xeb\x1b\x5e\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\xba\x0e\x00\x00\x00\x0f\x05\x5a\x5f\x5e\x58\xe9\x31\x00\x00\x00\xe8\xe0\xff\xff\xff\x2e\x2e\x2e\x2e\x57\x4f\x4f\x44\x59\x2e\x2e\x2e\x2e\x0a", CODE_SIZZ);
	add_section(&file, &payload);
	ft_strdel(&payload.code);
	return (0);
}
