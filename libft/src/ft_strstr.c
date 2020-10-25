/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:52:37 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/13 14:53:05 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j])
	{
		i = 0;
		while (haystack[j + i] == needle[i] && haystack[j + i] && needle[i])
			i++;
		if (!needle[i])
			return ((char *)&haystack[j]);
		j++;
	}
	return (NULL);
}
