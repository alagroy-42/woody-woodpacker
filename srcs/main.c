/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:06:20 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/21 10:30:42 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

int			main(int ac, char **av)
{
	t_file	file;

	ft_bzero(&file, sizeof(t_file));
	errno = -1;
	if (ac != 2 || check_file(av[1], &file) == EXIT_FAILURE)
		woody_error(&file);
	encrypt_code(&file);
	t_payload payload = {malloc(CODE_SIZE), CODE_SIZE, 0x60, 0x1e, 0x2a, 0x7c};
	ft_memcpy(payload.code, DECRYPTION_CODE, CODE_SIZE);
	inject(&file, &payload);
	ft_strdel(&payload.code);
	return (0);
}
