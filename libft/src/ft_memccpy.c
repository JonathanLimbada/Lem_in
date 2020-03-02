/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:18:55 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/07 16:33:34 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if ((char *)d == NULL && (char *)s == NULL)
		return (d);
	while (i < n)
	{
		if (((unsigned char *)s)[i] != (unsigned char)c)
			((unsigned char *)d)[i] = ((unsigned char *)s)[i];
		else
		{
			((unsigned char *)d)[i] = ((unsigned char *)s)[i];
			return (d + (i + 1));
		}
		i++;
	}
	return (NULL);
}
