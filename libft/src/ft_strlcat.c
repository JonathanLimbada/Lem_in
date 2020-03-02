/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:21:38 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/07 16:22:06 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t k;
	size_t x;

	i = 0;
	k = 0;
	x = 0;
	while (dst[i])
		i++;
	while (src[x])
		x++;
	while (src[k] && i + k + 1 < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	if (dstsize <= i)
		return (dstsize + x);
	else
		return (i + x);
}
