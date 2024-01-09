/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:17 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/09 18:35:59 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_listnew(int newdata)
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

static void	listaddlast(t_list *sentinel, t_list *new)
{
	t_list	*last;

	last = sentinel->prev;
	last->next = new;
	new->prev = last;
	new->next = sentinel;
	sentinel->prev = new;
}

static t_list	*get_min_inorder(t_list **list)
{
	t_list	*current;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	current = (*list)->next;
	if (current != NULL)
	{
		while (current != *list)
		{
			if ((current->index == -1) && (has_min == 0 || current->data < min->data))
			{
				min = current;
				has_min = 1;
			}
			current = current->next;
		}
	}
	return (min);
}

void add_index2list(t_list **list)
{
	t_list	*current;
	int		index;

	index = 0;
	current = get_min_inorder(list);
	while (current != NULL)
	{
		current->index = index++;
		current = get_min_inorder(list);
	}
}

void check_arg_isdigit(long tmp, char *str)
{
	if (tmp < 0)
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			put_ori_error("Error");
		str++;
	}
}

t_list	*ft_createlist(char **argv)
{
	size_t	i;
	long	tmp;
	int		data;
	t_list	*current;
	t_list	*sentinel;

	i = 0;
	sentinel = create_sentinel();
	while (argv[i] != NULL)
	{
		tmp = ft_atoi(argv[i]);
		check_arg_isdigit(tmp, argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			put_ori_error("Error");
		data = (int)tmp;
		current = ft_listnew(data);
		listaddlast(sentinel, current);
		i++;
	}
	add_index2list(&sentinel);
	return (sentinel);
}
