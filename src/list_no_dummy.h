/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_no_dummy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:28:58 by samin             #+#    #+#             */
/*   Updated: 2021/06/11 16:34:15 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NO_DUMMY_H
# define LIST_NO_DUMMY_H

# include <stdlib.h>

typedef	struct	s_node
{
	int				content;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef	struct	s_dlist
{
	t_node	*head;
	t_node	*tail;
}				t_dlist;

void			ft_dlst_init(t_dlist *list);

void			ft_dlstadd_tail(t_dlist *list, int content);

#endif
