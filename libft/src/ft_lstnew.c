/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduffey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:15:22 by jduffey           #+#    #+#             */
/*   Updated: 2019/06/10 10:50:18 by jduffey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	if (!(head = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		head->content = NULL;
		head->content_size = 0;
	}
	else
	{
		if ((head->content = malloc(content_size)) == NULL)
		{
			free(head);
			return (NULL);
		}
		ft_memcpy((head->content), content, content_size);
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}
