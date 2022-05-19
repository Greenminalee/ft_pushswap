/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_no_dummy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:06:45 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 22:02:35 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_no_dummy.h"

void	ft_dlst_init(t_dlist *list)
{
	list->head = NULL;
	list->tail = NULL;
}

void	ft_node_new(t_node *new_node, int content)
{
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
}

void	ft_dlstadd_tail(t_dlist *list, int content)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (new_node)
	{
		if (list->head == NULL)
		{
			list->head = new_node;
			list->tail = new_node;
		}
		else
		{
			new_node->prev = list->tail;
			list->tail->next = new_node;
			list->tail = new_node;
		}
	}
}
