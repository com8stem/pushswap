/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishizu <kishizu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:36:11 by kishizu           #+#    #+#             */
/*   Updated: 2024/01/05 17:39:42 by kishizu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_ori_error(char *error_message)
{
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
