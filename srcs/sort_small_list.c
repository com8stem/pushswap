/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:35:50 by kishizu           #+#    #+#             */
/*   Updated: 2024/02/06 21:23:39 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_list(t_list **a)
{
	if ((*a)->next->data > (*a)->next->next->data)
		ra(a);
	return ;
}

static void	sort_three_list(t_list **a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = (*a)->next;
	second = first->next;
	third = second->next;
	if (!(first->data > second->data && second->data < third->data
			&& first->data > third->data) && !(first->data < second->data
			&& second->data > third->data && first->data > third->data))
	{
		sa(a);
		first = (*a)->next;
		second = first->next;
		third = second->next;
	}
	if (first->data > second->data)
		ra(a);
	else if (first->data > third->data)
		rra(a);
}

static void	sort_four_list(t_list **a, t_list **b)
{
	int	min_index;

	min_index = get_min_index(*a);
	if (min_index == 1)
		ra(a);
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_index == 3)
		rra(a);
	if (issorted(*a))
		return ;
	pb(a, b);
	sort_three_list(a);
	pa(a, b);
}

static void	sort_five_list(t_list **a, t_list **b)
{
	int	min_index;

	min_index = get_min_index(*a);
	if (min_index == 1)
		ra(a);
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_index == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_index == 4)
		rra(a);
	if (issorted(*a))
		return ;
	pb(a, b);
	sort_four_list(a, b);
	pa(a, b);
}

void	sort_small_list(t_list **a, t_list **b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two_list(a);
	else if (size == 3)
		sort_three_list(a);
	else if (size == 4)
		sort_four_list(a, b);
	else if (size == 5)
		sort_five_list(a, b);
}
