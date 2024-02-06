/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:13 by kishizu           #+#    #+#             */
/*   Updated: 2024/02/06 21:14:41 by kishizu          ###   ########.fr       */
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

void	put_ori_error(char *error_message);
int		check_argc(int argc);
int		check_list_data(t_list *list);
t_list	*create_sentinel(void);
t_list	*ft_createlist(char **argv);

t_list	*ft_listnew(int newdata);
void	listaddlast(t_list *sentinel, t_list *new);
int		ps_atoi(const char *str);

int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);

int		round_listsize(t_list *list);
int		issorted(t_list *list);
int		get_min_list(t_list *list);
int		get_min_index(t_list *list);

void	sort_small_list(t_list **a, t_list **b, int size);
void	sort_large_list(t_list **a, t_list **b, int size);

#endif