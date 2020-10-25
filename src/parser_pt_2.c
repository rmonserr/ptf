/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_pt_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:39:43 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/02 18:39:44 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		read_precision_2(t_params *data)
{
	if ((data->format[data->counter] == '.') &&
		!(data->format[data->counter + 1] <= '9'
		&& data->format[data->counter + 1] >= '0'))
	{
		data->counter++;
		if (data->format[data->counter] == '*')
		{
			data->precision = va_arg(data->args, int);
			if (data->precision <= 0 && data->precision != -5)
				data->precision = -5;
			data->counter++;
		}
		else
			data->precision = 0;
	}
}

void		sort_flags(t_params *data)
{
	if (data->minus_sign == 1 && data->zero == 1)
		data->zero = 0;
	if (data->plus_sign == 1 && data->space == 1)
		data->space = 0;
}

void		read_size(t_params *data)
{
	size_t		h_size;
	size_t		l_size;

	h_size = 0;
	l_size = 0;
	while (data->format[data->counter] == 'h' ||
		data->format[data->counter] == 'l' ||
		data->format[data->counter] == 'L')
	{
		if (data->format[data->counter] == 'h')
			h_size++;
		if (data->format[data->counter] == 'l')
			l_size++;
		if (data->format[data->counter] == 'L')
			data->size = 5;
		data->counter++;
	}
	if (h_size == 2)
		data->size = 4;
	if (h_size == 1)
		data->size = 3;
	if (l_size == 2)
		data->size = 2;
	if (l_size == 1)
		data->size = 1;
}

void		type_parsing(t_params *data)
{
	char	*output;

	if (data->type == 'd' || data->type == 'i')
		print_int(data);
	if (data->type == 'c' || data->type == 'C')
		print_char(data);
	if (data->type == 's' || data->type == 'S')
		print_string(data);
	if (data->type == 'o' || data->type == 'O')
		print_octal(data);
	if (data->type == 'u' || data->type == 'U')
		print_unsigned(data);
	if (data->type == 'x' || data->type == 'X')
		print_hexadecimal(data);
	if (data->type == 'p')
		print_pointer(data);
	if (data->type == 'f')
		print_start_f(data);
	if (data->type == '%')
	{
		output = use_flag(data, "%", 1);
		ft_putstr(output);
		data->total += ft_strlen(output);
	}
}
