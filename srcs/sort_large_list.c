#include "push_swap.h"

// static int get_max_bit(t_list *list)
// {
// 	t_list *current;
// 	int max_data;
// 	int max_bit;

// 	current = list->next;
// 	max_data = current->data;
// 	max_bit = 0;
// 	while(current != list)
// 	{
// 		if (current->data > max_data)
// 			max_data = current->data;
// 		current = current->next;
// 	}
// 	while ((max_data >> max_bit) != 0)
// 		max_bit++;
// 	return (max_bit);
// }

void sort_large_list(t_list **a, t_list **b, int size)
{
	int i;
	int j;
	// int max_bits;
	t_list *current_a;

	// max_bits = get_max_bit(*a);
	i = 0;
	while (issorted(*a) == 0)
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
