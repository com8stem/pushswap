/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:17 by kishizu           #+#    #+#             */
/*   Updated: 2023/12/11 19:30:02 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_listnew(int newdata, int index)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = newdata;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list *createSentinel()
{
    t_list *sentinel;

	sentinel = (t_list *)malloc(sizeof(t_list));
	if (sentinel == NULL)
		return (NULL);
	sentinel->data = -1; // ダミーデータ、実際のデータは持たない
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	return (sentinel);
}

void	ft_listaddlast(t_list *sentinel, t_list *new)
{
	t_list	*last;

	last = sentinel->prev;
	last->next = new;
	new->prev = last;
	new->next = sentinel;
	sentinel->prev = new;
}

t_list	*ft_createlist(char **argv)
{
	size_t	i;
	long	tmp;
	int		data;
	t_list	*current;
	t_list	*sentinel;

	i = 0;
	sentinel = createSentinel();
	while (argv[i] != NULL)
	{
		tmp = ft_atoi(argv[i]);
		if (tmp > INT_MAX)
			put_ori_error("Error!");
		data = (int)tmp;
		current = ft_listnew(data, i - 1);
		ft_listaddlast(sentinel, current);
		i++;
	}
	return (sentinel);
}
