/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:24 by kishizu           #+#    #+#             */
/*   Updated: 2023/12/11 19:50:30 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ft_split(char **ptr)
{
	size_t i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static int get_max_bit(t_list *list)
{
	t_list *current;
	int max_data;
	int max_bit;

	current = list->next;
	max_data = current->data;
	max_bit = 0;
	while(current != list)
	{
		if (current->data > max_data)
			max_data = current->data;
		current = current->next;
	}
	while ((max_data >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

static int get_min_list(t_list *list, int limit)
{
	t_list *current;
	int		min_data;

	current = list->next;
	min_data = current->data;
	while (current != list)
	{
		if (current->data < min_data && current->data != limit)
			min_data = current->data;
		current = current->next;
	}
	return (min_data);
}

int issorted(t_list *list)
{
	t_list *current;
	int tmp;

	current = list->next;
	tmp = current->data;
	while (current != list)
	{
		if (current->data < tmp)
			return(0);
		tmp = current->data;
		current = current->next;
	}
	return (1);
}

static void sort_two_list(t_list **a)
{
	if ((*a)->next->data > (*a)->next->next->data)
		ra(a);
	return ;
}

static void sort_three_list(t_list **a)
{
	t_list	*current;
	int min_data;
	int next_min_data;

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

static void	sort_small_list(t_list **a, t_list **b, int size)
{
	(void)b;
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two_list(a);
	else if (size == 3)
		sort_three_list(a);
	// else if (size == 4)
	// {
	// 	pb(a, b);
	// 	sort_three_list(a, b);
	// 	pa(a, b);
	// }
	// else if (size == 5)
	// else if (size == 6)
}

static void sort_large_list(t_list **a, t_list **b, int size)
{
	int i;
	int j;
	int max_bits;
	t_list *current_a;

	max_bits = get_max_bit(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current_a = (*a)->next;
			if (((current_a->data >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (round_listsize(*b) != 0)
		{
			pa(a, b);
		}
		i++;
		printf("----------------\n");
	}

}
void	sort_list(t_list **a, t_list **b)
{
	int size;

	size = round_listsize(*a);
	if (size < 6)
		sort_small_list(a, b, size);
	else
		sort_large_list(a, b, size);
}

void	init_list(int argc, char **argv, t_list **a, t_list **b)
{
	char	**tmp_argv;

	if (argc == 2)
	{
		tmp_argv = ft_split(argv[1], ' ');
		if (tmp_argv == NULL)
			put_ori_error("malloc");
		*a = ft_createlist(tmp_argv);
		free_ft_split(tmp_argv);
	}
	else
		*a = ft_createlist(&argv[1]);
	*b = createSentinel();
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	check_argc(argc);
	init_list(argc, argv, &a, &b);
	
	displayList(a);

	sort_list(&a, &b);

	displayList(a);
	displayList(b);

	return (0);
}
