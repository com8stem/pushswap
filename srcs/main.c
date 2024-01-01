/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:40:24 by kishizu           #+#    #+#             */
/*   Updated: 2023/12/11 19:50:30 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ft_split(char **ptr)
{
	size_t i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	init_list(int argc, char **argv, t_list **a, t_list **b)
{
	char	**tmp_argv;

	if (argc == 2)
	{
		tmp_argv = ft_split(argv[1], ' ');
		if (tmp_argv == NULL)
			put_ori_error("malloc");
		*a = ft_createlist(tmp_argv);
		free_ft_split(tmp_argv);
	}
	else
		*a = ft_createlist(&argv[1]);
	*b = createSentinel();
}

void	sort_list(t_list **a, t_list **b)
{
	int size;

	size = round_listsize(*a);
	if (size < 6)
		sort_small_list(a, b, size);
	else
		sort_large_list(a, b, size);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	check_argc(argc);
	init_list(argc, argv, &a, &b);
	
	displayList(a);

	sort_list(&a, &b);

	displayList(a);
	displayList(b);

	return (0);
}
