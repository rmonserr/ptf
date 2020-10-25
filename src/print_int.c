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

int			print_zero(t_params *data)
{
	if (data->precision == 0 && !data->width)
	{
		data->printed = 0;
		return (1);
	}
	if (!data->precision && data->width)
	{
		data->printed = 0;
		while (data->width--)
			ft_putchar(' ');
		return (1);
	}
	if (!data->precision)
	{
		data->printed = 0;
		return (1);
	}
	return (0);
}

char		*put_minus(int len, char *str)
{
	char	*new;
	int		counter;

	counter = 1;
	new = ft_strnew(len + 1);
	new[0] = '-';
	while (counter != len + 1)
	{
		new[counter] = str[counter - 1];
		counter++;
	}
	return (new);
}

char		*print_int_3(t_params *data, int len, char *str)
{
	char	*new;
	int		count;
	char	c;

	if (data->zero == 1)
		c = '0';
	else
		c = ' ';
	count = 0;
	if (data->width >= 0 && data->width > len)
	{
		new = ft_strnew(data->width - len);
		while (count < data->width - len)
			new[count++] = c;
		if (data->minus_sign == 1)
			new = ft_strjoin(str, new);
		else
			new = ft_strjoin(new, str);
		if (data->negative == 1 && data->zero == 1)
			new = move_minus(new);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

char		*print_int_2(t_params *data, int len, char *str)
{
	char	*new;
	int		count;

	count = 0;
	if (data->precision > 0 && data->precision >= len)
	{
		new = ft_strnew(data->precision - len);
		while (count < data->precision - len)
			new[count++] = '0';
		if (data->negative == 1)
			new = put_minus((int)ft_strlen(new), new);
		new = ft_strjoin(new, str);
		ft_strdel(&str);
		return (new);
	}
	if ((data->precision <= 0 || data->precision <= len)
		&& (data->negative == 1))
	{
		new = put_minus(len, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

void		print_int(t_params *data)
{
	int		arg;
	int		len;
	char	*str;

	arg = va_arg(data->args, int);
	if (data->zero == 1 && data->precision > 0)
		data->zero = 0;
	if (arg < 0)
	{
		str = ft_itoa(arg * (-1));
		data->negative = 1;
	}
	else
		str = ft_itoa(arg);
	if ((int)ft_strlen(str) == 1 && str[0] == '0')
		if ((data->trigger = print_zero(data)) == 1)
			return ;
	len = (int)ft_strlen(str);
	str = print_int_2(data, len, str);
	len = (int)ft_strlen(str);
	str = print_int_3(data, len, str);
	ft_putstr(str);
	data->total += (int)ft_strlen(str);
	ft_strdel(&str);
}
