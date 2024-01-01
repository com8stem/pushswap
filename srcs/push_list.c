#include "push_swap.h"

static t_list	*push_list(t_list **from, t_list **to)
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
	from_second->prev = (*from);
	(*from)->next = from_second;
	return (*to);
}

int pa(t_list **a, t_list **b)
{
	push_list(b, a);
	ft_putendl_fd("pa", STDOUT_FILENO);
	return (NO_ERROR);
}

int pb(t_list **a, t_list **b)
{
	push_list(a, b);
	ft_putendl_fd("pb", STDOUT_FILENO);
	return (NO_ERROR);
}
