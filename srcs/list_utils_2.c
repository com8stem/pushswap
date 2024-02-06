/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:54:41 by kishizu           #+#    #+#             */
/*   Updated: 2024/02/06 21:14:33 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_listnew(int newdata)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		put_ori_error("malloc error");
	new->data = newdata;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	listaddlast(t_list *sentinel, t_list *new)
{
	t_list	*last;

	last = sentinel->prev;
	last->next = new;
	new->prev = last;
	new->next = sentinel;
	sentinel->prev = new;
}

int	ps_atoi(const char *str)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (10 * num) + (*str - '0');
		str++;
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			put_ori_error("Error");
	}
	return ((int)(num * sign));
}
