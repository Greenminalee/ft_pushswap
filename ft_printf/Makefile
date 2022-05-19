# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samin <samin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 20:46:03 by samin             #+#    #+#              #
#    Updated: 2021/06/11 16:21:23 by samin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= ./ft_printf.c ./ft_check_flag.c\
			  ./ft_print_c.c ./ft_print_s.c\
			  ./ft_print_d.c ./ft_print_u.c\
			  ./ft_print_x.c ./ft_print_p.c\
			  ./ft_print_percent.c\
			  ./ft_util.c ./ft_libft.c
OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all
