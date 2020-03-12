/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:33:28 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/07 16:18:57 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (s)
	{
		i = 0;
		p = (char *)malloc(sizeof(char) * len + 1);
		if (p == NULL)
			return (NULL);
		while (i < len)
			p[i++] = s[start++];
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
