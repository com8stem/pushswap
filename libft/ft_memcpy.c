#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				index;

	d = dst;
	s = src;
	index = 0;
	if (dst != NULL || src != NULL)
	{
		while (index < n)
		{
			d[index] = s[index];
			index++;
		}
	}
	return (dst);
}