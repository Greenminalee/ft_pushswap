/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:44:40 by samin             #+#    #+#             */
/*   Updated: 2021/03/05 21:13:52 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p_1(t_flag *flag, long long content, char padding_char)
{
	while (flag->padding_len-- > 0)
	{
		ft_putchar_fd(padding_char, 1);
		flag->length++;
	}
	ft_putstr_fd("0x", 1);
	flag->length += 2;
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

void	print_p_2(t_flag *flag, long long content, char padding_char)
{
	ft_putstr_fd("0x", 1);
	flag->length += 2;
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

void	type_p(t_flag *flag, va_list ap)
{
	long long	content;
	char		padding_char;

	content = va_arg(ap, long long);
	custum_number_len(flag, content);
	padding_char = flag_exception(flag);
	if (flag->dot == 1 && flag->precision > flag->content_len)
		flag->precision_len = flag->precision - flag->content_len;
	flag->padding_len =
		flag->width - (flag->precision_len + flag->content_len) - 2;
	if (flag->minus == 0)
		print_p_1(flag, content, padding_char);
	else
		print_p_2(flag, content, padding_char);
}
