/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:01:54 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/13 15:44:04 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(const char *s)
{
	int		i;
	int		j;
	int		spaces;
	char	*rtrn;

	j = -1;
	i = -1;
	spaces = 0;
	while ((s[++i] == '\n' || s[i] == ' ' || s[i] == '\t') && s[i])
		spaces++;
	if (s[i])
		while (s[i])
			i++;
	else
		return (ft_strnew(0));
	while (s[--i] == '\n' || s[i] == ' ' || s[i] == '\t')
		spaces++;
	if (!(rtrn = ft_strnew(ft_strlen(s) - spaces)))
		return (NULL);
	i = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	while ((unsigned int)++j < ft_strlen(s) - spaces)
		rtrn[j] = s[i + j];
	return (rtrn);
}

char		*ft_strtrim(const char *s)
{
	if (!s)
		return (NULL);
	return (ft_trim(s));
}
