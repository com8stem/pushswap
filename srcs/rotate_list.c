/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:36:04 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/05 17:39:27 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*rotate_list(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = (*list)->next;
	second = (*list)->next->next;
	last = (*list)->prev;
	(*list)->next = second;
	(*list)->prev = first;
	first->next = *list;
	first->prev = last;
	last->next = first;
	second->prev = *list;
	return (*list);
}

int	ra(t_list **a)
{
	rotate_list(a);
	ft_putendl_fd("ra", STDOUT_FILENO);
	return (NO_ERROR);
}

int	rb(t_list **b)
{
	rotate_list(b);
	ft_putendl_fd("rb", STDOUT_FILENO);
	return (NO_ERROR);
}

int	rr(t_list **a, t_list **b)
{
	rotate_list(a);
	rotate_list(b);
	ft_putendl_fd("rr", STDOUT_FILENO);
	return (NO_ERROR);
}
