/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:57:35 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/11 14:19:58 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_charcount(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			k++;
		while (s[i] != c && s[i])
			i++;
	}
	return (k);
}

static int	ft_letter_count(char const *s, char c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (s[i] == c)
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		l;
	char	**p;

	i = -1;
	k = 0;
	if (!s || !(p = (char **)malloc(sizeof(*p) * ft_charcount(s, c) + 1)))
		return (NULL);
	while (++i < ft_charcount(s, c))
	{
		l = 0;
		if (!(p[i] = ft_strnew(ft_letter_count(&s[k], c) + 1)))
			p[i] = NULL;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			p[i][l++] = s[k++];
		p[i][l] = '\0';
	}
	p[i] = NULL;
	return (p);
}
