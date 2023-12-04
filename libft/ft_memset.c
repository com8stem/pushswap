#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	size_t			index;

	dest = b;
	index = 0;
	while (index < len)
	{
		dest[index] = (unsigned char) c;
		index++;
	}
	return (b);
}