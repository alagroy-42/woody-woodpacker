/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:27:14 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/17 16:29:46 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strreplace(char *str, char find, char replace)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == find)
			str[i] = replace;
	return (str);
}
