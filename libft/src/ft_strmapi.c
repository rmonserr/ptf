/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:26:59 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/20 16:27:00 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*freshstr;

	if (s == NULL || f == NULL)
		return (NULL);
	freshstr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (freshstr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		freshstr[i] = f(i, s[i]);
		i++;
	}
	freshstr[i] = '\0';
	return (freshstr);
}
