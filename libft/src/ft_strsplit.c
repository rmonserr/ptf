/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:36:27 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/21 11:36:29 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_word_len(const char *str, char c)
{
	int len;

	len = 1;
	while (*str != c && *str)
	{
		str++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**strarr;

	i = 0;
	j = 0;
	if (!s || (!(strarr = (char**)malloc(sizeof(char*) *
		ft_word_count(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(strarr[i] = (char*)malloc(sizeof(char ) * ft_word_len(s, c))))
				return (NULL);
			while (*s && *s != c)
				strarr[i][j++] = (char)*s++;
			strarr[i++][j] = '\0';
			j = 0;
		}
	}
	strarr[i] = NULL;
	return (strarr);
}
