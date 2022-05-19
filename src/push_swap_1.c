/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:19:17 by samin             #+#    #+#             */
/*   Updated: 2021/06/13 16:58:13 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_dlist *stack)
{
	t_node *a;
	t_node *b;
	t_node *c;
	t_node *d;

	if (stack->head == NULL || stack->tail == NULL ||
		stack->head->next == NULL || stack->tail->prev == NULL)
		return ;
	a = stack->head;
	b = stack->head->next;
	c = stack->tail->prev;
	d = stack->tail;
	d->next = a;
	a->prev = d;
	d->prev = NULL;
	c->next = NULL;
	stack->head = d;
	stack->tail = c;
}

void	ft_rr(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_reverse_rotate(t_dlist *stack)
{
	t_node *a;
	t_node *b;
	t_node *c;
	t_node *d;

	if (stack->head == NULL || stack->tail == NULL ||
		stack->head->next == NULL || stack->tail->prev == NULL)
		return ;
	a = stack->head;
	b = stack->head->next;
	c = stack->tail->prev;
	d = stack->tail;
	a->prev = d;
	d->next = a;
	a->next = NULL;
	b->prev = NULL;
	stack->head = b;
	stack->tail = a;
}

void	ft_rrr(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}

void	command(char *op, t_dlist *stack_a, t_dlist *stack_b)
{
	if (ft_strncmp(op, "rra", 3) == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		ft_rrr(stack_a, stack_b);
	else if (ft_strncmp(op, "sa", 2) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strncmp(op, "pa", 2) == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(op, "rr", 2) == 0)
		ft_rr(stack_a, stack_b);
	ft_printf("%s\n", op);
}
