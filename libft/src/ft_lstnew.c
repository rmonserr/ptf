/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:06:24 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/28 13:06:25 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlst;

	newlst = (t_list *)malloc(sizeof(t_list));
	if (newlst == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlst->content_size = 0;
		newlst->content = NULL;
	}
	else
	{
		newlst->content = (t_list *)malloc(content_size);
		if (newlst->content == NULL)
			return (NULL);
		ft_memcpy((newlst->content), content, content_size);
		newlst->content_size = content_size;
	}
	newlst->next = NULL;
	return (newlst);
}
