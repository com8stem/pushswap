/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:24 by kishizu           #+#    #+#             */
/*   Updated: 2024/02/09 18:44:21 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_ft_split(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static void	init_list(int argc, char **argv, t_list **a, t_list **b)
{
	char	**tmp_argv;

	if (argc == 2)
	{
		tmp_argv = ft_split(argv[1], ' ');
		if (tmp_argv == NULL)
			put_ori_error("malloc error");
		*a = ft_createlist(tmp_argv);
		free_ft_split(tmp_argv);
	}
	else
		*a = ft_createlist(&argv[1]);
	*b = create_sentinel();
}

static void	sort_list(t_list **a, t_list **b)
{
	int	size;

	if (issorted(*a))
		return ;
	size = round_listsize(*a);
	if (size < 6)
		sort_small_list(a, b, size);
	else
		sort_large_list(a, b, size);
}

static void	free_list(t_list *a, t_list *b)
{
	t_list	*current;
	t_list	*next_list;

	current = a->next;
	while (current != a)
	{
		next_list = current->next;
		free(current);
		current = next_list;
	}
	free (a);
	free (b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	check_argc(argc);
	init_list(argc, argv, &a, &b);
	check_list_data(a);
	sort_list(&a, &b);
	free_list(a, b);
	return (0);
}
