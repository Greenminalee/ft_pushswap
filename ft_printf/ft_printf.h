/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:45:46 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 20:53:46 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flag
{
	int		minus;
	int		zero;
	int		star;
	int		width;
	int		precision;
	char	type;
	int		dot;
	int		length;
	int		content_len;
	int		padding_len;
	int		precision_len;
}				t_flag;

int				ft_printf(const char *format, ...);
void			init(t_flag *flag);
void			flag_check(char **format, t_flag *flag, va_list ap);
void			width_check(char **format, t_flag *flag, va_list ap);
void			precision_check(char **format, t_flag *flag, va_list ap);
void			type_check(char **format, t_flag *flag);
void			type_station(t_flag *flag, va_list ap);
void			type_c(t_flag *flag, va_list ap);
void			print_c_1(t_flag *flag, char content);
void			print_c_2(t_flag *flag, char content);
void			type_s(t_flag *flag, va_list ap);
void			print_s_1(t_flag *flag, char *content);
void			print_s_2(t_flag *flag, char *content);
void			type_d(t_flag *flag, va_list ap);
void			print_d_1(t_flag *flag, int content, char padding_char);
void			print_d_2(t_flag *flag, int content, char padding_char);
void			type_u(t_flag *flag, va_list ap);
void			print_u_1(t_flag *flag, unsigned int content,
										char padding_char);
void			print_u_2(t_flag *flag, unsigned int content,
										char padding_char);
void			type_x(t_flag *flag, va_list ap);
void			print_x_1(t_flag *flag, unsigned int content,
										char padding_char);
void			print_x_2(t_flag *flag, unsigned int content,
										char padding_char);
void			type_p(t_flag *flag, va_list ap);
void			print_p_1(t_flag *flag, long long content, char padding_char);
void			print_p_2(t_flag *flag, long long content, char padding_char);
void			type_percent(t_flag *flag);
void			print_percent_1(t_flag *flag, char padding_char);
void			print_percent_2(t_flag *flag, char padding_char);
void			custum_number_len(t_flag *flag, long long content);
void			custum_putnbr_fd(t_flag *flag, long long n, int fd);
void			recur_du(long long n, int fd);
void			recur_xp(char type, long long n, int fd);
char			flag_exception(t_flag *flag);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);

#endif
