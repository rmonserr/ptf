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

void		print_char_with_width(t_params *data)
{
	int		counter;

	counter = data->width - 1;
	while (counter-- > 0)
	{
		ft_putchar(' ');
		data->total += 1;
	}
}

void		print_char(t_params *data)
{
	char	arg;

	arg = va_arg(data->args, int);
	if (data->printed && !data->width)
	{
		ft_putchar(arg);
		data->printed = 0;
		data->total += 1;
	}
	if (data->width != 0 && data->minus_sign)
	{
		ft_putchar(arg);
		data->printed = 0;
		data->total += 1;
		print_char_with_width(data);
	}
	else
	{
		print_char_with_width(data);
		ft_putchar(arg);
		data->total += 1;
		data->printed = 0;
	}
}
