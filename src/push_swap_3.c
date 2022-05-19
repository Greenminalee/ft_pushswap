/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:32:55 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 21:12:38 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_dlist *stack_1, t_dlist *stack_2)
{
	if (stack_1->head == NULL)
		return ;
	if (stack_1->head == stack_1->tail)
		ft_push_helper1(stack_1, stack_2);
	else
		ft_push_helper2(stack_1, stack_2);
}

void	ft_push_helper1(t_dlist *stack_1, t_dlist *stack_2)
{
	if (stack_2->head == NULL)
	{
		stack_2->head = stack_1->tail;
		stack_2->tail = stack_1->tail;
		stack_1->head = NULL;
		stack_1->tail = NULL;
	}
	else
	{
		stack_1->tail->prev = stack_2->tail;
		stack_2->tail->next = stack_1->tail;
		stack_2->tail = stack_2->tail->next;
		stack_2->tail->next = NULL;
		stack_1->head = NULL;
		stack_1->tail = NULL;
	}
}

void	ft_push_helper2(t_dlist *stack_1, t_dlist *stack_2)
{
	t_node *tmp_node;

	if (stack_2->head == NULL)
	{
		stack_2->head = stack_1->tail;
		stack_2->tail = stack_1->tail;
		stack_1->tail->prev->next = NULL;
		stack_1->tail = stack_1->tail->prev;
		stack_2->tail->prev = NULL;
		stack_2->tail->next = NULL;
	}
	else
	{
		tmp_node = stack_1->tail->prev;
		stack_1->tail->prev->next = NULL;
		stack_1->tail->prev = stack_2->tail;
		stack_2->tail->next = stack_1->tail;
		stack_1->tail->next = NULL;
		stack_2->tail = stack_1->tail;
		stack_1->tail = tmp_node;
	}
}
