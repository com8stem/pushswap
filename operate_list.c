/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:29 by kishizu           #+#    #+#             */
/*   Updated: 2023/12/11 19:25:53 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_swap(t_list **list)
{
    if (*list != NULL && (*list)->next != NULL && (*list)->next->next != NULL)
	{
        t_list *first = (*list)->next;
        t_list *second = (*list)->next->next;

        // Update the links for the first element
        first->next = (*list)->next->next->next;
		first->prev = second;

        // Update the links for the second element
        second->next = first;
        second->prev = *list;

        // Update the links for the third element
		(*list)->next = second;

        // Update the links for the element after the second element (if it exists)
        if (second->next != NULL)
            second->next->prev = second;
	}

	return (*list);
}

t_list	*ft_push(t_list **from, t_list **to)
{
	t_list	*from_first;
	t_list	*from_second;
	t_list	*to_first;

	from_first = (*from)->next;
	if (from_first == *from)
		return (NULL);
	from_second = (*from)->next->next;
	if ((*to)->next == *to)
	{
		(*to)->prev = from_first;
		from_first->next = *to;
	}
	else
	{
		to_first = (*to)->next;
		from_first->next = to_first;
		to_first->prev = from_first;
	}
	(*to)->next = from_first;
	from_first->prev = *to;
	if (from_second != *from)
	{
		from_second->prev = (*from);
		(*from)->next = from_second;
	}
	return (*to);
}

t_list	*ft_rotate(t_list **list)
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

t_list	*ft_r_rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*secondfromlast;

	first = (*list)->next;
	last = (*list)->prev;
	secondfromlast = (*list)->prev->prev;

	(*list)->next = last;
	(*list)->prev = secondfromlast;
	first->prev = last;
	last->next = first;
	last->prev = *list;
	secondfromlast->next = *list;
	return (*list);
}
