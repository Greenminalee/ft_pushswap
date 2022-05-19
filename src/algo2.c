/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:32:49 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 16:35:14 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*cal_ra_or_rra(t_dlist stack_a, int idx1, int idx2, int *array)
{
	t_node	*cur;
	int		count_ra;
	int		count_rra;

	count_ra = 0;
	count_rra = 0;
	cur = stack_a.tail;
	while (!(cur->content <= array[idx1] && cur->content >= array[idx2]) &&
		cur != NULL)
	{
		cur = cur->prev;
		count_ra++;
	}
	cur = stack_a.head;
	while (!(cur->content <= array[idx1] && cur->content >= array[idx2]) &&
		cur != NULL)
	{
		cur = cur->next;
		count_rra++;
	}
	if (count_ra <= count_rra)
		return ("ra");
	else
		return ("rra");
	return ("");
}

char	*cal_rb_or_rrb(t_dlist stack_b, int num)
{
	t_node	*cur;
	int		count_rb;
	int		count_rrb;

	count_rb = 0;
	count_rrb = 0;
	cur = stack_b.tail;
	while (cur->content != num && cur != NULL)
	{
		cur = cur->prev;
		count_rb++;
	}
	cur = stack_b.head;
	while (cur->content != num && cur != NULL)
	{
		cur = cur->next;
		count_rrb++;
	}
	if (count_rb <= count_rrb)
		return ("rb");
	else
		return ("rrb");
	return ("");
}

void	atob(t_dlist *stack_a, t_dlist *stack_b, int *idx, int *ordered_array)
{
	int cnt;

	cnt = 0;
	while (1)
	{
		if (ordered_array[idx[0]] >= stack_a->tail->content &&
		ordered_array[idx[1]] <= stack_a->tail->content)
		{
			command("pb", stack_a, stack_b);
			cnt++;
		}
		else
			command(cal_ra_or_rra(*stack_a, idx[0], idx[1], ordered_array),
			stack_a, stack_b);
		if (cnt == idx[1] - idx[0] + 1)
			break ;
	}
}

void	btoa(t_dlist *stack_a, t_dlist *stack_b, int max, int *ordered_array)
{
	int idx;

	idx = 0;
	while (stack_b->head != NULL || idx < max)
	{
		if (ordered_array[idx] == stack_b->tail->content)
		{
			command("pa", stack_a, stack_b);
			idx++;
		}
		else
			command(cal_rb_or_rrb(*stack_b, ordered_array[idx]),
			stack_a, stack_b);
	}
}
