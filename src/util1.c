/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:43:12 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 21:16:44 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	traversal_list(t_dlist stack)
{
	t_node	*cur;

	cur = stack.head;
	while (cur != NULL)
	{
		ft_printf("%d ", cur->content);
		cur = cur->next;
	}
}

void	stack_clear(t_dlist *stack)
{
	t_node	*cur;
	t_node	*next;

	cur = stack->head;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

void	free_str_array(int size, char **array)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int		is_order(t_dlist stack_a, int *ordered_array)
{
	int		i;
	t_node	*cur;
	int		check;

	i = 0;
	cur = stack_a.head;
	check = 1;
	while (cur != NULL)
	{
		if (cur->content != ordered_array[i])
		{
			check = 0;
			break ;
		}
		i++;
		cur = cur->next;
	}
	return (check);
}

void	create_stack(t_dlist *stack, char **splited_array, int size)
{
	int idx;

	idx = size;
	while (--idx >= 0)
		ft_dlstadd_tail(stack, ft_atoi(splited_array[idx]));
}
