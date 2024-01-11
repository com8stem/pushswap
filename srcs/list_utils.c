/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:36:23 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/11 18:21:39 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	round_listsize(t_list *list)
{
	t_list	*head;
	t_list	*current;
	int		size;

	head = list;
	current = list;
	size = 0;
	if (current->next == head)
		return (0);
	while (current->next != head)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int	issorted(t_list *list)
{
	t_list	*current;
	int		tmp;

	current = list->next;
	tmp = current->data;
	while (current != list)
	{
		if (current->data < tmp)
			return (0);
		tmp = current->data;
		current = current->next;
	}
	return (1);
}

int	get_min_list(t_list *list)
{
	t_list	*current;
	int		min_data;

	current = list->next;
	min_data = current->data;
	while (current != list)
	{
		if (current->data < min_data)
			min_data = current->data;
		current = current->next;
	}
	return (min_data);
}

int	get_min_index(t_list *list)
{
	t_list	*current;
	int		min_data;
	int		min_index;

	current = list->next;
	min_data = get_min_list(list);
	min_index = 0;
	while (current != list)
	{
		if (current->data == min_data)
			break ;
		current = current->next;
		min_index++;
	}
	return (min_index);
}

t_list	*create_sentinel(void)
{
	t_list	*sentinel;

	sentinel = (t_list *)malloc(sizeof(t_list));
	if (sentinel == NULL)
		put_ori_error("malloc error");
	sentinel->index = -1;
	sentinel->data = -1;
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	return (sentinel);
}
