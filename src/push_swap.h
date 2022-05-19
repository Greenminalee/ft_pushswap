/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 00:55:07 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 22:14:07 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list_no_dummy.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

void	ft_swap(t_dlist *stack);
void	ft_swap_helper1(t_dlist *stack);
void	ft_swap_helper2(t_dlist *stack);
void	ft_ss(t_dlist *stack_a, t_dlist *stack_b);

void	ft_push(t_dlist *stack_1, t_dlist *stack_2);
void	ft_push_helper1(t_dlist *stack_1, t_dlist *stack_2);
void	ft_push_helper2(t_dlist *stack_1, t_dlist *stack_2);

void	ft_rotate(t_dlist *stack);
void	ft_rr(t_dlist *stack_a, t_dlist *stack_b);
void	ft_reverse_rotate(t_dlist *stack);
void	ft_rrr(t_dlist *stack_a, t_dlist *stack_b);
void	command(char *op, t_dlist *stack_a, t_dlist *stack_b);

void	algo_3(t_dlist *stack_a, t_dlist *stack_b);
void	algo_3_helper(t_dlist *stack_a, t_dlist *stack_b);
void	algo_100(t_dlist *stack_a, t_dlist *stack_b,
						int max, int *ordered_array);
void	algo_500(t_dlist *stack_a, t_dlist *stack_b,
						int max, int *ordered_array);
void	algo_nomal(t_dlist *stack_a, t_dlist *stack_b,
						int max, int *ordered_array);

char	*cal_ra_or_rra(t_dlist stack_a, int idx1, int idx2, int *array);
char	*cal_rb_or_rrb(t_dlist stack_b, int num);
void	atob(t_dlist *stack_a, t_dlist *stack_b, int *idx, int *ordered_array);
void	btoa(t_dlist *stack_a, t_dlist *stack_b, int max, int *ordered_array);

void	traversal_list(t_dlist stack);
void	stack_clear(t_dlist *stack);
void	free_str_array(int size, char **array);
int		is_order(t_dlist stack_a, int *ordered_array);
void	create_stack(t_dlist *stack, char **splited_array, int size);

char	**trimed_argv(int argc, char **argv);
void	validate_argv(int value_num, char **array);
void	duplicate_check(int value_num, char **array);
int		*array_order(int value_num, char **array);
void	interger_check(int value_num, char **array);

#endif
