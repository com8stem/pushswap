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

void displayList(t_list *sentinel)
{
    if (sentinel->next == sentinel)
    {
        printf("リストは空です\n");
        return;
    }

    t_list *current = sentinel->next;
    while (current != sentinel) // 適当な回数で終了するように制限
    {
        printf("%d ", current->data);
        current = current->next;
    }
	printf("\n");
}

void	sort_list(t_list *a, t_list *b)
{
	int i;
	int	digits;
	t_list current;

	digits = a->prev->index;

	i = 0;
	while (i < digits)
	{
		if (a->data  >> i & 1)
			ft_push(a, &b);
	}
}

void	put_operation(char *op)
{
	write (STDOUT_FILENO, op, ft_strlen(op));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
	{
		ft_putendl_fd("Error!", STDOUT_FILENO);
		return (-1);
	}
	if (argc == 2)
		ft_push_swap_1();
	a = ft_createlist(argv);
	b = createSentinel();
	// displayList(b);

	// printf("双方向循環リンクリスト a: ");
    // displayList(a);

	// ft_swap(&a);
	// printf("swap: ");
    // displayList(a);

	// ft_push(&a, &b);
	// printf("push A a:");
    // displayList(a);
	// printf("push A b:");
    // displayList(b);

	// ft_rotate(&a);
	// printf("rotate a: ");
    // displayList(a);

	// ft_r_rotate(&a);
	// printf("r_rotate a: ");
    // displayList(a);

	// ft_push(&a, &b);
	// ft_push(&a, &b);
	// printf("push B b:");
	// displayList(b);
	// ft_ss_swap(&a, &b);
	// printf("ss a:");
	// displayList(a);
	// printf("ss b:");
	// displayList(b);
	
	// ft_rr_rotate(&a, &b);
	// printf("rr a:");
	// displayList(a);
	// printf("rr b:");
	// displayList(b);

	// ft_reverse_rr_rotate(&a, &b);
	// printf("rrr a:");
	// displayList(a);
	// printf("rrr b:");
	// displayList(b);
    // リストに割り当てられたメモリを解放
    free(a);
}
