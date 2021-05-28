/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:06:20 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/28 15:03:46 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

int			main(int ac, char **av)
{
	t_file		file;
	t_payload	payload;

	ft_bzero(&file, sizeof(t_file));
	errno = 0;
	if (ac != 2 || check_file(av[1], &file) == EXIT_FAILURE)
		woody_error(&file, NULL, NULL, !errno ? ERROR_ARGS : ERROR_ERRNO);
	encrypt_code(&file);
	payload = (t_payload){malloc(CODE_SIZE), CODE_SIZE, 0x1e, 0x23, 0x2a, 0x7c, 0x60};
	ft_memcpy(payload.code, DECRYPTION_CODE, CODE_SIZE);
	inject(&file, &payload);
	ft_strdel(&payload.code);
	return (0);
}
