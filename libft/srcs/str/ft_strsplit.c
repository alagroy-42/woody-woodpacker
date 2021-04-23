/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:07:46 by alagroy-          #+#    #+#             */
/*   Updated: 2019/04/15 13:52:33 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fill(const char *s, char c, int nb_words, char **rtrn)
{
	int	i;
	int	j;
	int	size_word;

	size_word = 1;
	i = 0;
	j = -1;
	while (s[i] == c)
		i++;
	while (++j < nb_words)
	{
		while (s[++i] != c && s[i])
			size_word++;
		if (!(rtrn[j] = ft_strsub(s, i - size_word, size_word)))
			return (NULL);
		size_word = 1;
		while (s[i] == c)
			i++;
	}
	return (rtrn);
}

char		**ft_strsplit(const char *s, char c)
{
	int		nb_words;
	char	**rtrn;
	int		i;

	i = 0;
	if (!s || !c || !s[0])
		return (NULL);
	nb_words = (s[0] == c) ? 0 : 1;
	while (s[++i])
		if (s[i - 1] && s[i] && s[i] != c && s[i - 1] == c)
			nb_words++;
	if (s[0] == '\0')
		nb_words = 0;
	if (!(rtrn = (char **)malloc((nb_words + 1) * sizeof(char *))))
		return (NULL);
	rtrn[nb_words] = NULL;
	return (ft_fill(s, c, nb_words, rtrn));
}
