#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;

	index = 0;
	if (s == NULL || f == NULL)
		return ;
	while (*s != '\0')
	{
		if (f != NULL)
			(*f)(index, s);
		s++;
		index++;
	}
}