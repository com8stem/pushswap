#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (ss1[index] != ss2[index])
		{
			return ((int)(ss1[index] - ss2[index]));
		}
		index++;
	}
	return (0);
}