/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:13 by kishizu           #+#    #+#             */
/*   Updated: 2023/12/05 16:32:50 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define NO_ERROR 0

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void put_ori_error(char *error_message);

int check_argc(int argc);

void	displayList(t_list *sentinel);
t_list	*ft_createlist(char **argv);

int	pa(t_list **a,t_list **b);
int	pb(t_list **a,t_list **b);
int	sa(t_list **a);
int	sb(t_list **b);
int	ss(t_list **a, t_list **b);
int	ra(t_list **a);
int	rb(t_list **b);
int	rr(t_list **a, t_list **b);
int	rra(t_list **a);
int	rrb(t_list **b);
int	rrr(t_list **a, t_list **b);

t_list *createSentinel();
int round_listsize(t_list *list);


#endif