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

void		print_pointer(t_params *data)
{
	unsigned long long int	ptr;
	char					*output;
	long int				len;

	data->hash = 1;
	ptr = (unsigned long long int)va_arg(data->args, void *);
	if (ptr == 0)
	{
		data->hash = 0;
		output = "(nil)";
		data->width = 0;
		data->precision = 0;
	}
	else
		output = hex_calculation(ptr, data);
	len = (long int)ft_strlen(output);
	output = print_octal_2(data, output, len);
	len = (long int)ft_strlen(output);
	output = print_octal_3(data, output, len);
	ft_putstr(output);
	data->total += (int)ft_strlen(output);
	ft_strdel(&output);
}
