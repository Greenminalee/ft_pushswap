/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:45:28 by samin             #+#    #+#             */
/*   Updated: 2021/03/05 21:14:27 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x_1(t_flag *flag, unsigned int content, char padding_char)
{
	while (flag->padding_len-- > 0)
	{
		ft_putchar_fd(padding_char, 1);
		flag->length++;
	}
	while (flag->precision_len-- > 0)
	{
		custum_putnbr_fd(flag, 0, 1);
		flag->length++;
	}
	if (!(flag->dot == 1 && flag->precision == 0 && content == 0))
	{
		custum_putnbr_fd(flag, content, 1);
		flag->length += flag->content_len;
	}
}

void	print_x_2(t_flag *flag, unsigned int content, char padding_char)
{
	while (flag->precision_len-- > 0)
	{
		custum_putnbr_fd(flag, 0, 1);
		flag->length++;
	}
	if (!(flag->dot == 1 && flag->precision == 0 && content == 0))
	{
		custum_putnbr_fd(flag, content, 1);
		flag->length += flag->content_len;
	}
	while (flag->padding_len-- > 0)
	{
		ft_putchar_fd(padding_char, 1);
		flag->length++;
	}
}

void	type_x(t_flag *flag, va_list ap)
{
	unsigned int	content;
	char			padding_char;

	content = va_arg(ap, unsigned int);
	custum_number_len(flag, content);
	padding_char = flag_exception(flag);
	if (flag->dot == 1 && flag->precision > flag->content_len)
		flag->precision_len = flag->precision - flag->content_len;
	flag->padding_len =
		flag->width - (flag->precision_len + flag->content_len);
	if (flag->minus == 0)
		print_x_1(flag, content, padding_char);
	else
		print_x_2(flag, content, padding_char);
}
