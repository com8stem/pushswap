#include "push_swap.h"

int check_argc(int argc)
{
	if (argc < 2)
	{
		ft_putendl_fd("Error!", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	return (NO_ERROR);
}
