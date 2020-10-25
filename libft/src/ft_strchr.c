/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:02:03 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/13 14:02:07 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)s;
	while (tmp[i] && tmp[i] != c)
	{
		i++;
	}
	if (tmp[i] == c)
		return (&tmp[i]);
	else
		return (NULL);
}
