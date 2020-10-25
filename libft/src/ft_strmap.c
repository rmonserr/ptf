/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:07:48 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/20 16:07:49 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
		freshstr[i] = f(s[i]);
		i++;
	}
	freshstr[i] = '\0';
	return (freshstr);
}
