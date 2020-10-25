/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:12:55 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/02 15:12:56 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*check_null(t_params *data, char *str)
{
	char *new;

	if (data->precision > -5 && data->precision < 6)
	{
		new = ft_strnew(0);
		return (new);
	}
	return (str);
}

char	*print_string_3(t_params *data, int len, char *str)
{
	char	*tmp;
	char	*new;
	int		count;

	count = 0;
	if (data->width > (long int)len)
	{
		tmp = ft_strnew(data->width - len);
		while (count < (int)(data->width - len))
		{
			if (data->zero == 0)
				tmp[count] = ' ';
			else
				tmp[count] = '0';
			count++;
		}
		if (data->minus_sign == 1)
			new = ft_strjoin(str, tmp);
		else
			new = ft_strjoin(tmp, str);
		ft_strdel(&tmp);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

char	*print_string_2(t_params *data, long int len, char *str)
{
	char	*new;
	int		count;

	count = 0;
	if (data->precision != -5 && data->precision < len)
	{
		new = ft_strnew((size_t)data->precision);
		while (count < (int)data->precision)
		{
			new[count] = str[count];
			count++;
		}
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

void	print_string(t_params *data)
{
	int		len;
	char	*str;

	str = va_arg(data->args, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
		str = check_null(data, str);
	}
	else
		str = ft_strdup(str);
	len = (int)ft_strlen(str);
	str = print_string_2(data, (long int)len, str);
	len = (int)ft_strlen(str);
	str = print_string_3(data, len, str);
	ft_putstr(str);
	data->total += (int)ft_strlen(str);
	ft_strdel(&str);
}
