/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:51:29 by rmonserr          #+#    #+#             */
/*   Updated: 2020/06/30 13:51:35 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		clean_struct(t_params *data)
{
	data->precision = -5;
	data->width = 0;
	data->minus_sign = 0;
	data->plus_sign = 0;
	data->space = 0;
	data->zero = 0;
	data->hash = 0;
	data->size = 0;
	data->type = '\0';
	data->negative = 0;
	data->printed = 0;
	data->trigger = 0;
}

t_params	*init(t_params *data, char *format)
{
	data->format = format;
	data->precision = -5;
	data->width = 0;
	data->minus_sign = 0;
	data->plus_sign = 0;
	data->space = 0;
	data->zero = 0;
	data->hash = 0;
	data->size = 0;
	data->negative = 0;
	data->type = '\0';
	data->printed = 0;
	data->trigger = 0;
	data->counter = 0;
	data->specifier_mask = "sSpdDioOuUxXfcC";
	data->flag_mask = "+- 0#";
	data->output_str = "\0";
	data->total = 0;
	return (data);
}
