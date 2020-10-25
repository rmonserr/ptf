/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:35:31 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/28 13:35:33 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst1;
	t_list *lst2;

	if (!alst)
		return ;
	lst2 = *alst;
	while (lst2)
	{
		lst1 = lst2->next;
		del(lst2->content, lst2->content_size);
		free(lst2);
		lst2 = lst1;
	}
	*alst = NULL;
}
