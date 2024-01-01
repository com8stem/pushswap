#include "push_swap.h"

int round_listsize(t_list *list)
{
	t_list *head;
	t_list *current;
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

int get_min_list(t_list *list, int limit)
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

int get_min_index(t_list *list)
{
	t_list *current;
	int		min_data;
	int		min_index;

	current = list->next;
	min_data = get_min_list(list, -1);
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

void displayList(t_list *sentinel)
{
    if (sentinel->next == sentinel)
    {
        printf("Empty list\n");
        return;
    }
    t_list *current = sentinel->next;
    while (current != sentinel) // 適当な回数で終了するように制限
    {
        printf("[%d]", current->data);
        current = current->next;
    }
	printf("\n");
}
