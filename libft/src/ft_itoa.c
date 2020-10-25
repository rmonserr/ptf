/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:58:37 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/19 15:58:38 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoa(int n)
{
	int					size;
	long long int		res;
	char				*str;
	int					flag;

	flag = (n < 0) ? (-1) : 1;
	size = (n < 0) ? 3 : 2;
	res = n;
	while (res /= 10)
		size++;
	if ((str = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	str[--size] = '\0';
	while (size > 0)
	{
		str[--size] = n % 10 * flag + '0';
		n /= 10;
	}
	if (flag < 0)
		str[0] = '-';
	return (str);
}
