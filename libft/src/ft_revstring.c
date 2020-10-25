/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:08:26 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/28 18:08:28 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_revstring(char *str)
{
	char	*revstr;
	int		i;
	int		j;

	revstr = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (revstr == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(str);
	while (j)
		revstr[i++] = str[--j];
	revstr[i] = '\0';
	return (revstr);
}
