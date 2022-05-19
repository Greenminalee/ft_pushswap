/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:44:58 by samin             #+#    #+#             */
/*   Updated: 2021/03/05 21:27:48 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent_1(t_flag *flag, char padding_char)
{
	while (flag->padding_len-- > 0)
	{
		ft_putchar_fd(padding_char, 1);
		flag->length++;
	}
	ft_putchar_fd('%', 1);
	flag->length++;
}

void	print_percent_2(t_flag *flag, char padding_char)
{
	ft_putchar_fd('%', 1);
	flag->length++;
	while (flag->padding_len-- > 0)
	{
		ft_putchar_fd(padding_char, 1);
		flag->length++;
	}
}

void	type_percent(t_flag *flag)
{
	char padding_char;

	padding_char = flag_exception(flag);
	flag->padding_len = flag->width - 1;
	if (flag->minus == 0)
		print_percent_1(flag, padding_char);
	else
		print_percent_2(flag, padding_char);
}
