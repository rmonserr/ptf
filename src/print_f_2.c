/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:01:38 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/19 16:01:40 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_one(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_strnew(ft_strlen(str) + 1);
	if (str[0] == '-')
	{
		res[0] = '-';
		res[1] = '1';
		i = 1;
	}
	else
		res[0] = '1';
	while (str[i] != '\0')
	{
		res[i + 1] = str[i];
		i++;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*rounding(t_params *data, char *output)
{
	int	i;
	int	len;

	if (data->hash && data->precision == 0)
		len = ft_strlen(output) - 2;
	else
		len = ft_strlen(output) - 1;
	i = 0;
	while (len - i >= 0)
	{
		if (output[len - i] == '9')
		{
			output[len - i] = '0';
			if (len == i || output[len - i - 1] == '-')
				output = add_one(output);
		}
		else if (output[len - i] >= '0')
		{
			output[len - i]++;
			break ;
		}
		i++;
	}
	return (output);
}

char	*copy(char *output, char *str)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		output[i] = str[i];
		i++;
	}
	return (output);
}

char	*floatld_inf_or_nan(int mant, int sign)
{
	char	*ret;

	ret = NULL;
	if (mant == 0)
	{
		if (sign == 1)
			ret = ft_strdup("-inf");
		else
			ret = ft_strdup("inf");
	}
	else if (mant != 0)
		ret = ft_strdup("nan");
	return (ret);
}
