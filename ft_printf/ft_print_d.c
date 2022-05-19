/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:44:31 by samin             #+#    #+#             */
/*   Updated: 2021/03/05 21:13:29 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d_1(t_flag *flag, int content, char padding_char)
{
	if (padding_char == '0' && content < 0)
	{
		ft_putchar_fd('-', 1);
		content *= -1;
	}
	while (flag->padding_len-- > 0)
	{
		ft_putchar_fd(padding_char, 1);
		flag->length++;
	}
	if (padding_char == ' ' && content < 0)
	{
		ft_putchar_fd('-', 1);
		content *= -1;
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

void	print_d_2(t_flag *flag, int content, char padding_char)
{
	if (content < 0)
	{
		ft_putchar_fd('-', 1);
		content *= -1;
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
	while (flag->padding_len-- > 0)
	{
		ft_putchar_fd(padding_char, 1);
		flag->length++;
	}
}

void	type_d(t_flag *flag, va_list ap)
{
	int		content;
	char	padding_char;

	content = va_arg(ap, int);
	custum_number_len(flag, content);
	padding_char = flag_exception(flag);
	if (flag->dot == 1 && flag->precision > flag->content_len)
		flag->precision_len = flag->precision - flag->content_len;
	flag->padding_len =
		flag->width - (flag->precision_len + flag->content_len);
	if (content < 0)
	{
		flag->padding_len--;
		flag->length++;
	}
	if (flag->minus == 0)
		print_d_1(flag, content, padding_char);
	else
		print_d_2(flag, content, padding_char);
}
