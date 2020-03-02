/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:33:42 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/07 10:35:46 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;
	size_t s2_len;

	i = 0;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	if (s2_len == 0)
		return ((char*)s1);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < len && s1[i + j] != '\0')
			j++;
		if (j == s2_len)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
