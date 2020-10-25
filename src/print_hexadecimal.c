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

char		*check_hash(t_params *data, char *res)
{
	if (data->hash == 1)
	{
		if (data->type == 'x' || data->type == 'p')
			res = ft_strjoin(res, "x0");
		else
			res = ft_strjoin(res, "X0");
	}
	return (res);
}

char		*if_letter(long long int num, char *res, t_params *data)
{
	char	*a_z;
	char	*new;
	char	*str;

	new = ft_strnew(1);
	a_z = "abcdefABCDEF";
	if (data->type == 'x' || data->type == 'p')
		new[0] = a_z[num - 10];
	else
		new[0] = a_z[num - 4];
	str = ft_strjoin(res, new);
	ft_strdel(&new);
	ft_strdel(&res);
	return (str);
}

char		*check_remainder(unsigned long long int number,
	char *res, char *temp, t_params *data)
{
	if (number % 16 != 0)
	{
		if (number % 16 >= 10 && number % 16 <= 15)
			res = if_letter((number % 16), res, data);
		else
		{
			temp = ft_itoa(number % 16);
			res = ft_strjoin(res, temp);
		}
	}
	return (res);
}

char		*hex_calculation(unsigned long long int number, t_params *data)
{
	char				*res;
	__uintmax_t			tmp;
	char				*temp;

	res = ft_strnew(0);
	while (number / 16)
	{
		tmp = number / 16;
		if (number % 16 >= 10 && number % 16 <= 15)
			res = if_letter((number % 16), res, data);
		else
		{
			temp = ft_itoa(number % 16);
			res = ft_strjoin(res, temp);
			ft_strdel(&temp);
		}
		number = tmp;
	}
	res = check_remainder(number, res, temp, data);
	res = check_hash(data, res);
	res = ft_revstring(res);
	return (res);
}

void		print_hexadecimal(t_params *data)
{
	char						*output;
	int							len;
	unsigned long long int		arg;

	arg = va_arg(data->args, unsigned long long int);
	if (arg == 0 && data->precision != 0)
		output = ft_itoa(arg);
	else
		output = hex_calculation(arg, data);
	len = (long int)ft_strlen(output);
	output = print_octal_2(data, output, len);
	len = (long int)ft_strlen(output);
	output = print_octal_3(data, output, len);
	ft_putstr(output);
	data->total += (int)ft_strlen(output);
	ft_strdel(&output);
}
