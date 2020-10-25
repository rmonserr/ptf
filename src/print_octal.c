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

char		*octal_calculation(unsigned long long int number, t_params *data)
{
	char				*res;
	__uintmax_t			tmp;
	char				*temp;

	res = ft_strnew(0);
	while (number / 8)
	{
		tmp = number / 8;
		temp = ft_itoa(number % 8);
		res = ft_strjoin(res, temp);
		number = tmp;
	}
	if (number % 8 != 0)
	{
		temp = ft_itoa(number % 8);
		res = ft_strjoin(res, temp);
	}
	if (data->hash == 1)
		res = ft_strjoin(res, "0");
	res = ft_revstring(res);
	return (res);
}

char		*print_octal_3(t_params *data, char *str, int len)
{
	char	*new;
	int		count;
	char	c;

	count = 0;
	if (data->zero == 1 && data->precision < 0)
		c = '0';
	else
		c = ' ';
	if (data->width && data->width > len)
	{
		new = ft_strnew(data->width - len);
		while (count < data->width - len)
			new[count++] = c;
		if (data->minus_sign)
			new = ft_strjoin(str, new);
		else
			new = ft_strjoin(new, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

char		*print_octal_2(t_params *data, char *str, int len)
{
	char	*new;
	int		count;

	count = 0;
	if (data->precision > 0 && data->precision > len)
	{
		new = ft_strnew(data->precision - len);
		while (count < data->precision - len)
			new[count++] = '0';
		new = ft_strjoin(new, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

void		print_octal(t_params *data)
{
	char						*output;
	int							len;
	unsigned long long int		arg;

	arg = va_arg(data->args, unsigned long long int);
	if (arg == 0 && data->precision != 0)
		output = ft_itoa(arg);
	else
		output = octal_calculation(arg, data);
	len = (long int)ft_strlen(output);
	output = print_octal_2(data, output, len);
	len = (long int)ft_strlen(output);
	output = print_octal_3(data, output, len);
	ft_putstr(output);
	data->total += (int)ft_strlen(output);
	ft_strdel(&output);
}
