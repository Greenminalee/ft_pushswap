/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 01:42:24 by samin             #+#    #+#             */
/*   Updated: 2021/03/05 21:16:43 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s_1(t_flag *flag, char *content)
{
	while (flag->padding_len--)
	{
		ft_putchar_fd(' ', 1);
		flag->length++;
	}
	while (flag->content_len--)
	{
		ft_putchar_fd(*content, 1);
		content++;
		flag->length++;
	}
}

void	print_s_2(t_flag *flag, char *content)
{
	while (flag->content_len--)
	{
		ft_putchar_fd(*content, 1);
		content++;
		flag->length++;
	}
	while (flag->padding_len--)
	{
		ft_putchar_fd(' ', 1);
		flag->length++;
	}
}

void	type_s(t_flag *flag, va_list ap)
{
	char	*content;

	content = va_arg(ap, char *);
	if (content == NULL)
		content = "(null)";
	flag->content_len = ft_strlen(content);
	if (flag->dot == 1 && flag->content_len > flag->precision)
		flag->content_len = flag->precision;
	if (flag->width > flag->content_len)
		flag->padding_len = flag->width - flag->content_len;
	if (flag->minus == 0)
		print_s_1(flag, content);
	else
		print_s_2(flag, content);
}
