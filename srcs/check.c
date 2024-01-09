/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:36:28 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/05 18:01:46 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argc(int argc)
{
	if (argc < 2)
	{
		ft_putendl_fd("Error", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	return (NO_ERROR);
}
