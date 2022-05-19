/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:31 by samin             #+#    #+#             */
/*   Updated: 2021/06/13 16:04:07 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3(t_dlist *stack_a, t_dlist *stack_b)
{
	if (stack_a->tail->content > stack_a->tail->prev->content &&
	stack_a->tail->content > stack_a->head->content &&
	stack_a->tail->prev->content < stack_a->head->content)
		command("ra", stack_a, stack_b);
	else if (stack_a->tail->content < stack_a->tail->prev->content &&
	stack_a->tail->content > stack_a->head->content &&
	stack_a->tail->prev->content > stack_a->head->content)
		command("rra", stack_a, stack_b);
	else if (stack_a->tail->content > stack_a->tail->prev->content &&
	stack_a->tail->content < stack_a->head->content &&
	stack_a->tail->prev->content < stack_a->head->content)
		command("sa", stack_a, stack_b);
	algo_3_helper(stack_a, stack_b);
}

void	algo_3_helper(t_dlist *stack_a, t_dlist *stack_b)
{
	if (stack_a->tail->content > stack_a->tail->prev->content &&
	stack_a->tail->content > stack_a->head->content &&
	stack_a->tail->prev->content > stack_a->head->content)
	{
		command("ra", stack_a, stack_b);
		command("sa", stack_a, stack_b);
	}
	else if (stack_a->tail->content < stack_a->tail->prev->content &&
	stack_a->tail->content < stack_a->head->content &&
	stack_a->tail->prev->content > stack_a->head->content)
	{
		command("rra", stack_a, stack_b);
		command("sa", stack_a, stack_b);
	}
}

void	algo_100(t_dlist *stack_a, t_dlist *stack_b,
						int max, int *ordered_array)
{
	int i;
	int idx[2];

	i = -1;
	idx[0] = 0;
	idx[1] = 19;
	while (++i < 5)
	{
		atob(stack_a, stack_b, idx, ordered_array);
		idx[0] += 20;
		idx[1] += 20;
	}
	btoa(stack_a, stack_b, max, ordered_array);
}

void	algo_500(t_dlist *stack_a, t_dlist *stack_b,
						int max, int *ordered_array)
{
	int i;
	int idx[2];

	i = -1;
	idx[0] = 0;
	idx[1] = 49;
	while (++i < 10)
	{
		atob(stack_a, stack_b, idx, ordered_array);
		idx[0] += 50;
		idx[1] += 50;
	}
	btoa(stack_a, stack_b, max, ordered_array);
}

void	algo_nomal(t_dlist *stack_a, t_dlist *stack_b,
					int max, int *ordered_array)
{
	if (stack_b->head == NULL && is_order(*stack_a, ordered_array) == 1)
		return ;
	if (max == 100)
		algo_100(stack_a, stack_b, max, ordered_array);
	else if (max == 500)
		algo_500(stack_a, stack_b, max, ordered_array);
	else
	{
		while (max > 3)
		{
			while (stack_a->tail->content != ordered_array[max - 1])
				command("ra", stack_a, stack_b);
			command("pb", stack_a, stack_b);
			max -= 1;
		}
	}
	if (max == 2)
	{
		if (stack_a->head->content < stack_a->tail->content)
			command("ra", stack_a, stack_b);
	}
	else if (max == 3)
		algo_3(stack_a, stack_b);
	while (stack_b->head != NULL)
		command("pa", stack_a, stack_b);
}
