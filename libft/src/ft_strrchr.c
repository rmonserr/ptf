/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:42:31 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/23 15:54:21 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)s;
	while (tmp[i])
		i++;
	while (tmp[i] != tmp[0] && tmp[i] != c)
	{
		i--;
	}
	if (tmp[i] == c)
		return (&tmp[i]);
	else
		return (0);
}
