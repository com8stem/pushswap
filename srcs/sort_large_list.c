/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:36:00 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/09 18:34:11 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bit(t_list **list)
{
	t_list	*current;
	int		max;
	int		max_bit;

	current = (*list)->next;
	max = current->data;
	max_bit = 0;
	while (current != *list)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	sort_large_list(t_list **a, t_list **b, int size)
{
	int		i;
	int		j;
	t_list	*current_a;
	int		max_bits;

	max_bits = get_max_bit(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current_a = (*a)->next;
			if (((current_a->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (round_listsize(*b) != 0)
			pa(a, b);
		i++;
	}
}
