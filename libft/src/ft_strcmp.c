/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:47:28 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/11 15:21:10 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0)
		return (1);
	else if (((unsigned char)s1[i] - (unsigned char)s2[i]) < 0)
		return (-1);
	else
		return (0);
}
