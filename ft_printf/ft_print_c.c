/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:44:04 by samin             #+#    #+#             */
/*   Updated: 2021/03/06 00:52:24 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c_1(t_flag *flag, char content)
{
	flag->width--;
	while (flag->width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		flag->length++;
	}
	ft_putchar_fd(content, 1);
	flag->length++;
}

void	print_c_2(t_flag *flag, char content)
{
	ft_putchar_fd(content, 1);
	flag->length++;
	flag->width--;
	while (flag->width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		flag->length++;
	}
}

void	type_c(t_flag *flag, va_list ap)
{
	char	content;

	content = (char)va_arg(ap, int);
	if (flag->minus == 0)
		print_c_1(flag, content);
	else
		print_c_2(flag, content);
}
