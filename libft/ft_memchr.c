#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				index;

	p = (const unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (p[index] == (unsigned char)c)
		{
			return ((void *)&p[index]);
		}
		index++;
	}
	return (NULL);
}