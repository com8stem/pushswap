/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operate_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:20 by kishizu           #+#    #+#             */
/*   Updated: 2023/12/04 21:40:21 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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