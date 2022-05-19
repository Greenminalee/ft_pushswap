/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:16:09 by samin             #+#    #+#             */
/*   Updated: 2021/06/13 15:27:19 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_dlist	stack_a;
	t_dlist	stack_b;
	int		value_num;
	char	**splited_array;
	int		*ordered_array;

	value_num = 0;
	if (argc == 1)
		return (0);
	splited_array = trimed_argv(argc, argv);
	while (splited_array[value_num] != NULL)
		value_num++;
	ft_dlst_init(&stack_a);
	ft_dlst_init(&stack_b);
	validate_argv(value_num, splited_array);
	duplicate_check(value_num, splited_array);
	interger_check(value_num, splited_array);
	ordered_array = array_order(value_num, splited_array);
	create_stack(&stack_a, splited_array, value_num);
	algo_nomal(&stack_a, &stack_b, value_num, ordered_array);
	free_str_array(value_num, splited_array);
	free(ordered_array);
	stack_clear(&stack_a);
	return (0);
}
