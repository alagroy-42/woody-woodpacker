/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:45:02 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/17 18:47:55 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vct_print(t_vector *vct)
{
	write(1, vct->value, vct->len);
}

void	vct_printendl(t_vector *vct)
{
	write(1, vct->value, vct->len);
	ft_putchar('\n');
}

void	vct_dprint(t_vector *vct, int fd)
{
	write(fd, vct->value, vct->len);
}

void	vct_dprintendl(t_vector *vct, int fd)
{
	write(fd, vct->value, vct->len);
	ft_putchar_fd('\n', fd);
}
