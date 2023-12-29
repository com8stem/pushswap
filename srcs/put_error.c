#include "push_swap.h"

void put_ori_error(char *error_message)
{
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
