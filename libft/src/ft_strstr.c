/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:22:27 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/07 16:35:10 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (s2[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j] && j < len)
		{
			j++;
		}
		if (j == len)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
