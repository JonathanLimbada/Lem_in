/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:50:57 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/07 16:22:37 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = dst;
	if (dst == NULL && src == NULL && !(len <= 0))
		return (dst);
	if (dst > src)
	{
		while ((int)(--len) >= 0)
			temp[len] = ((char *)src)[len];
	}
	else
	{
		while (i < len)
		{
			temp[i] = ((char *)src)[i];
			i++;
		}
	}
	dst = temp;
	return (dst);
}
