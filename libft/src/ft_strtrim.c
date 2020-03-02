/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:17:42 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/11 14:56:30 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	int			k;
	char		*p;

	if (!s)
		return (NULL);
	i = 0;
	k = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		if (s[i] == '\0')
			return (ft_strnew(1));
	}
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	p = ft_strsub(s, i, (k - i) + 1);
	return (p);
}
