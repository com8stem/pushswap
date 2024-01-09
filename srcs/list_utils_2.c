/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:54:41 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/09 20:55:14 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_listnew(int newdata)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = newdata;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	listaddlast(t_list *sentinel, t_list *new)
{
	t_list	*last;

	last = sentinel->prev;
	last->next = new;
	new->prev = last;
	new->next = sentinel;
	sentinel->prev = new;
}
