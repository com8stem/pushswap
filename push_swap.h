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
# include "./libft/libft.h"

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	displayList(t_list *sentinel);
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