/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:36:28 by kishizu           #+#    #+#             */
/*   Updated: 2024/02/06 15:19:22 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argc(int argc)
{
	if (argc < 2)
	{
		exit(EXIT_SUCCESS);
	}
	return (NO_ERROR);
}

static int	check_data_dup(int data_count, int *data_copy)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < data_count - 1)
	{
		num = data_copy[i];
		j = i + 1;
		while (j < data_count)
		{
			if (num == data_copy[j])
				put_ori_error("Error");
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}

int	check_list_data(t_list *list)
{
	t_list	*current;
	int		data_count;
	int		*data_copy;
	int		i;

	current = list->next;
	data_count = round_listsize(list);
	if (data_count == 0)
		put_ori_error("Error");
	data_copy = (int *)malloc(data_count * sizeof(int));
	i = 0;
	while (i < data_count)
	{
		data_copy[i] = current->data;
		current = current->next;
		i++;
	}
	check_data_dup(data_count, data_copy);
	free(data_copy);
	return (NO_ERROR);
}
