/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:46:48 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/18 11:46:50 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_end;

	i = 0;
	if (size == 0)
		return (ft_strlen(dst));
	while (dst[i] && i < size)
		i++;
	src_end = i;
	while (src[i - src_end] && i < size - 1)
	{
		dst[i] = src[i - src_end];
		i++;
	}
	if (src_end < size)
		dst[i] = '\0';
	return (src_end + ft_strlen(src));
}
