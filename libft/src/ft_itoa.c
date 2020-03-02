/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:08:45 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/10 10:26:42 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*p;
	long	k;
	int		i;

	k = n;
	i = len(k);
	if (!(p = ft_strnew(i)))
		return (NULL);
	p[i--] = '\0';
	if (k == 0)
	{
		p[0] = 48;
		return (p);
	}
	if (k < 0)
	{
		p[0] = '-';
		k = k * -1;
	}
	while (k > 0)
	{
		p[i--] = 48 + (k % 10);
		k = k / 10;
	}
	return (p);
}
