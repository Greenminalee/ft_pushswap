/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:18:59 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 10:49:40 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_dlist *stack)
{
	if (stack->head == NULL || stack->tail == NULL ||
		stack->head->next == NULL || stack->tail->prev == NULL)
		return ;
	if (stack->head == stack->tail->prev)
		ft_swap_helper1(stack);
	else
		ft_swap_helper2(stack);
}

void	ft_swap_helper1(t_dlist *stack)
{
	t_node *tmp;

	tmp = stack->tail;
	stack->tail = stack->head;
	stack->tail->next = NULL;
	stack->head = tmp;
	stack->head->next = stack->tail;
	stack->tail->prev = stack->head;
	stack->head->prev = NULL;
}

void	ft_swap_helper2(t_dlist *stack)
{
	t_node *tail_node;
	t_node *pre_tail_node;
	t_node *pre_pre_tail_node;

	tail_node = stack->tail;
	pre_tail_node = tail_node->prev;
	pre_pre_tail_node = pre_tail_node->prev;
	pre_pre_tail_node->next = tail_node;
	tail_node->next = pre_tail_node;
	pre_tail_node->next = NULL;
	tail_node->prev = pre_pre_tail_node;
	pre_tail_node->prev = tail_node;
	stack->tail = pre_tail_node;
}

void	ft_ss(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
