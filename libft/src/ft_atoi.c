/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:24:30 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/12 14:24:32 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long long int	res;
	long long int	flag;

	flag = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (res > res * 10 + (*str - '0'))
		{
			if (flag == -1)
				return (0);
			else
				return (-1);
		}
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res *= flag);
}
