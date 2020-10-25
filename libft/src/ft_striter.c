/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:28:24 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/18 14:28:26 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_striter(char *s, void (*f) (char *))
{
	if (s == NULL || f == NULL)
		return ;
	else
		while (*s)
			f(s++);
}
