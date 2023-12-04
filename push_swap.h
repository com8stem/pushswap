#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_list
{
	int		data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void 	displayList(t_list *sentinel);
t_list	*ft_createlist(char **argv);
t_list	*ft_swap(t_list **list);
t_list	*ft_push(t_list **from, t_list **to);
t_list	*ft_rotate(t_list **list);
t_list	*ft_r_rotate(t_list **list);
void	ft_ss_swap(t_list **a, t_list **b);
void	ft_rr_rotate(t_list **a, t_list **b);
void	ft_reverse_rr_rotate(t_list **a, t_list **b);




t_list *createSentinel();




#endif