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

char		*move_minus(char *str)
{
	int		count;
	char	*new;
	char	tmp;

	count = 0;
	new = ft_strnew((int)ft_strlen(str));
	new = ft_strdup(str);
	while (new[count] != '-')
		count++;
	while (count > 0 && new[count])
	{
		if (new[count - 1] == ' ')
			break ;
		tmp = new[count - 1];
		new[count - 1] = new[count];
		new[count] = tmp;
		count--;
	}
	return (new);
}

void		print_unsigned(t_params *data)
{
	char			*output;
	int				len;
	__uintmax_t		arg;

	arg = va_arg(data->args, unsigned long int);
	if (arg == 0 && data->precision == 0)
		output = ft_strnew(0);
	else
		output = ft_itoa(arg);
	len = (long int)ft_strlen(output);
	output = print_octal_2(data, output, len);
	len = (long int)ft_strlen(output);
	output = print_octal_3(data, output, len);
	ft_putstr(output);
	data->total += (int)ft_strlen(output);
	ft_strdel(&output);
}
