/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:45:39 by samin             #+#    #+#             */
/*   Updated: 2021/03/06 00:52:54 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->star = 0;
	flag->width = 0;
	flag->precision = 0;
	flag->type = 0;
	flag->dot = 0;
	flag->content_len = 0;
	flag->padding_len = 0;
	flag->precision_len = 0;
}

void	type_station(t_flag *flag, va_list ap)
{
	if (flag->type == 'c')
		type_c(flag, ap);
	else if (flag->type == 's')
		type_s(flag, ap);
	else if (flag->type == 'p')
		type_p(flag, ap);
	else if (flag->type == 'd' || flag->type == 'i')
		type_d(flag, ap);
	else if (flag->type == 'i')
		type_d(flag, ap);
	else if (flag->type == 'u')
		type_u(flag, ap);
	else if (flag->type == 'x' || flag->type == 'X')
		type_x(flag, ap);
	else if (flag->type == '%')
		type_percent(flag);
}

int		ft_printf(const char *format, ...)
{
	char	*non_const_format;
	va_list ap;
	t_flag	flag;

	non_const_format = (char*)format;
	va_start(ap, format);
	flag.length = 0;
	while (*non_const_format)
	{
		if (*non_const_format == '%')
		{
			init(&flag);
			non_const_format++;
			flag_check(&non_const_format, &flag, ap);
			type_station(&flag, ap);
		}
		else
		{
			ft_putchar_fd(*non_const_format, 1);
			non_const_format++;
			flag.length++;
		}
	}
	return (flag.length);
}
