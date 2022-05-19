# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samin <samin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 14:39:41 by hayelee           #+#    #+#              #
#    Updated: 2021/06/11 21:43:22 by samin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRCS =  ./src/list_no_dummy.c\
		./src/push_swap_1.c\
        ./src/push_swap_2.c\
		./src/push_swap_3.c\
		./src/algo1.c\
		./src/algo2.c\
		./src/util1.c\
		./src/util2.c\
		./src/main.c

OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBFT			= libft/libft.a
FT_PRINTF		= ft_printf/libftprintf.a
MK				= make

all:		$(NAME)

${LIBFT}:	
			$(MAKE) -C libft 

${FT_PRINTF}:
			$(MAKE) -C ft_printf

$(NAME):	${LIBFT} ${FT_PRINTF}
			$(CC) ${CFLAGS} -o ${NAME} ${SRCS} ${LIBFT} ${FT_PRINTF}
clean:
			$(MAKE) -C libft clean
			$(MAKE) -C ft_printf clean
			$(RM) $(OBJS)
fclean:		clean
				$(RM) $(NAME) $(FT_PRINTF) $(LIBFT)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
