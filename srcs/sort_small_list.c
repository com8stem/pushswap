/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:35:50 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/09 17:28:04 by kishizu          ###   ########.fr       */
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
	t_list	*current;
	int		min_data;
	int		next_min_data;

	current = (*a)->next;
	min_data = get_min_list(*a, -1);
	next_min_data = get_min_list(*a, min_data);
	if (issorted(*a))
		return ;
	if (current->data == min_data && current->next->data != next_min_data)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (current->data == next_min_data)
	{
		if (current->next->data == min_data)
			sa(a);
		else
			rra(a);
	}
	else
	{
		if (current->next->data == min_data)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

static void	sort_four_list(t_list **a, t_list **b)
{
	int	min_index;

	if (issorted(*a))
		return ;
	min_index = get_min_index(*a);
	// displaylist(*a);
	// printf("[%d]\n", min_index);
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

	if (issorted(*a))
		return ;
	min_index = get_min_index(*a);
	// printf("[%d]\n", min_index);
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
	(void)b;
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
