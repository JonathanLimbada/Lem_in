/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:50:18 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/07 16:24:46 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnew(size_t size)
{
	char		*p;
	size_t		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p != NULL)
	{
		while (i < size + 1)
			p[i++] = '\0';
		return (p);
	}
	return (NULL);
}
