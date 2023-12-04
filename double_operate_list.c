#include "push_swap.h"

void	ft_ss_swap(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_rr_rotate(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_reverse_rr_rotate(t_list **a, t_list **b)
{
	ft_r_rotate(a);
	ft_r_rotate(b);
}