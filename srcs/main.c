/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:06:20 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/26 14:44:57 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

int		main(int ac, char **av)
{
	t_file	file;
	int		error;

	ft_bzero(&file, sizeof(t_file));
	error = E_ARGS;
	if (ac != 2 || check_file(av[1], &file, &error) == EXIT_FAILURE)
		woody_error(error, &file);
	return (0);
}
