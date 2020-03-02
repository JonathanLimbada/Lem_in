/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:24:59 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/07 16:27:40 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*a;

	i = 0;
	if (!s)
		return (NULL);
	if (!(a = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		a[i] = f(s[i]);
		i++;
	}
	return (a);
}
