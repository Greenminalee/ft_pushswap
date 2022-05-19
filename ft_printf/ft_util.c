/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:45:55 by samin             #+#    #+#             */
/*   Updated: 2021/03/06 00:53:03 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	custum_number_len(t_flag *flag, long long content)
{
	if (content < 0)
		content *= -1;
	if (flag->dot == 1 && flag->precision == 0 && content == 0)
	{
		flag->content_len = 0;
		return ;
	}
	if (content == 0)
	{
		flag->content_len = 1;
		return ;
	}
	while (content != 0)
	{
		if (flag->type == 'd' || flag->type == 'u')
		{
			content /= 10;
			flag->content_len++;
		}
		else if (flag->type == 'x' || flag->type == 'X' || flag->type == 'p')
		{
			content /= 16;
			flag->content_len++;
		}
	}
}

void	recur_du(long long n, int fd)
{
	char num;

	num = (n % 10) + '0';
	if (n == 0)
		return ;
	n /= 10;
	recur_du(n, fd);
	write(fd, &num, 1);
}

void	recur_xp(char type, long long n, int fd)
{
	char		num;
	long long	mod;

	mod = n % 16;
	if (mod < 10)
		num = mod + '0';
	else
	{
		if (type == 'x' || type == 'p')
			num = mod - 10 + 'a';
		else if (type == 'X')
			num = mod - 10 + 'A';
	}
	if (n == 0)
		return ;
	n /= 16;
	recur_xp(type, n, fd);
	write(fd, &num, 1);
}

void	custum_putnbr_fd(t_flag *flag, long long n, int fd)
{
	char type;

	type = flag->type;
	if (fd < 0)
		return ;
	if (n < 0)
		n *= -1;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (type == 'd' || type == 'u')
		recur_du(n, fd);
	else if (type == 'x' || type == 'X' || type == 'p')
		recur_xp(type, n, fd);
}

char	flag_exception(t_flag *flag)
{
	if (flag->minus == 1)
		flag->zero = 0;
	if (flag->dot == 1 && flag->type != '%')
		flag->zero = 0;
	if (flag->zero == 1)
		return ('0');
	else
		return (' ');
}
