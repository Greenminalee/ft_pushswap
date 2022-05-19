/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:44:23 by samin             #+#    #+#             */
/*   Updated: 2021/03/05 20:57:58 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_check(char **format, t_flag *flag)
{
	if (**format == 'c')
		flag->type = 'c';
	else if (**format == 's')
		flag->type = 's';
	else if (**format == 'd' || **format == 'i')
		flag->type = 'd';
	else if (**format == 'u')
		flag->type = 'u';
	else if (**format == 'x')
		flag->type = 'x';
	else if (**format == 'X')
		flag->type = 'X';
	else if (**format == 'p')
		flag->type = 'p';
	else if (**format == '%')
		flag->type = '%';
	(*format)++;
}

void	width_check(char **format, t_flag *flag, va_list ap)
{
	if (**format == '*')
	{
		flag->width = va_arg(ap, int);
		(*format)++;
		if (flag->width < 0)
		{
			flag->minus = 1;
			flag->width *= -1;
		}
	}
	else
	{
		flag->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	precision_check(char **format, t_flag *flag, va_list ap)
{
	flag->dot = 1;
	(*format)++;
	if (**format == '*')
	{
		flag->precision = va_arg(ap, int);
		if (flag->precision < 0)
			flag->dot = 0;
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
	{
		flag->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	flag_check(char **format, t_flag *flag, va_list ap)
{
	while (flag->type == 0 && **format != '\0')
	{
		if (**format == '-')
		{
			flag->minus = 1;
			(*format)++;
		}
		else if (**format == '0')
		{
			flag->zero = 1;
			(*format)++;
		}
		else if ((**format >= '1' && **format <= '9') || (**format == '*'))
			width_check(format, flag, ap);
		else if ((**format) == '.')
			precision_check(format, flag, ap);
		else
			type_check(format, flag);
	}
}
