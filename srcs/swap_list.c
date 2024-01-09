/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:29 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/05 17:39:06 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*swap_list(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = (*list)->next;
	second = (*list)->next->next;
	third = (*list)->next->next->next;
	first->next = third;
	first->prev = second;
	third->prev = first;
	second->next = first;
	second->prev = *list;
	(*list)->next = second;
	return (*list);
}

int	sa(t_list **a)
{
	swap_list(a);
	ft_putendl_fd("sa", STDOUT_FILENO);
	return (NO_ERROR);
}

int	sb(t_list **b)
{
	swap_list(b);
	ft_putendl_fd("sb", STDOUT_FILENO);
	return (NO_ERROR);
}

int	ss(t_list **a, t_list **b)
{
	swap_list(a);
	swap_list(b);
	ft_putendl_fd("ss", STDOUT_FILENO);
	return (NO_ERROR);
}
