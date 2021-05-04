/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:06:20 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/04 14:28:31 by alagroy-         ###   ########.fr       */
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
	inject_decryption_routine(&file);
	return (0);
}
