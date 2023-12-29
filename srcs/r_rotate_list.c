#include "push_swap.h"

static t_list	*r_rotate_list(t_list **list)
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

int rra(t_list **a)
{
	r_rotate_list(a);
	ft_putendl_fd("rra", STDOUT_FILENO);
	return (NO_ERROR);
}

int rrb(t_list **b)
{
	r_rotate_list(b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
	return (NO_ERROR);
}

int rrr(t_list **a, t_list **b)
{
	r_rotate_list(a);
	r_rotate_list(b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
	return (NO_ERROR);
}
