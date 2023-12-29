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
        printf("%d ", current->data);
        current = current->next;
    }
	printf("\n");
}
