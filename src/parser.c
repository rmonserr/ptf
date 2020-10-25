/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:39:38 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/01 13:39:39 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

void		read_precision(t_params *data)
{
	int		tmp_counter;
	int		tmp_counter1;
	char	*tmp;

	if ((data->format[data->counter] == '.') &&
		(data->format[data->counter + 1] <= '9'
		&& data->format[data->counter + 1] >= '0'))
	{
		data->counter++;
		tmp_counter = 0;
		while (data->format[data->counter] >= '0' &&
			data->format[data->counter] <= '9')
		{
			data->counter++;
			tmp_counter++;
		}
		tmp = ft_strnew(tmp_counter);
		tmp_counter1 = data->counter;
		data->counter -= tmp_counter;
		tmp_counter = 0;
		while (data->counter != tmp_counter1)
			tmp[tmp_counter++] = data->format[data->counter++];
		data->precision = ft_atoi(tmp);
		free(tmp);
	}
}

void		read_width(t_params *data)
{
	char	*tmp;
	char	*new;

	new = ft_strnew(0);
	tmp = ft_strnew(1);
	if (data->format[data->counter] == '*')
	{
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus_sign = 1;
			data->width *= -1;
		}
		data->counter++;
		return ;
	}
	while (data->format[data->counter] >= '0' &&
		data->format[data->counter] <= '9')
	{
		tmp[0] = data->format[data->counter++];
		new = ft_strjoin(new, tmp);
	}
	data->width = ft_atoi(new);
	ft_strdel(&tmp);
	ft_strdel(&new);
}

void		read_flag(t_params *data)
{
	while ((ft_strchr(data->flag_mask, data->format[data->counter]) != NULL))
	{
		if (data->format[data->counter] == '#')
			data->hash = 1;
		if (data->format[data->counter] == '0')
			data->zero = 1;
		if (data->format[data->counter] == '+')
			data->plus_sign = 1;
		if (data->format[data->counter] == '-')
			data->minus_sign = 1;
		if (data->format[data->counter] == ' ')
			data->space = 1;
		data->counter++;
	}
}

void		parcer(t_params *data)
{
	read_flag(data);
	sort_flags(data);
	read_width(data);
	read_precision(data);
	read_precision_2(data);
	read_size(data);
	data->type = data->format[data->counter];
}

void		read_specifier(t_params *data)
{
	while (data->format[data->counter])
	{
		if (data->format[data->counter] == '%')
		{
			data->counter++;
			parcer(data);
			if ((check_space(data) == 1))
			{
				ft_putchar(' ');
				data->total += 1;
			}
			type_parsing(data);
			clean_struct(data);
		}
		else
		{
			ft_putchar(data->format[data->counter]);
			data->total += 1;
		}
		data->counter++;
	}
}
