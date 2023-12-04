#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	index = 0;
	if (n == 0)
		return (0);
	while (us1[index] != '\0' && us2[index] != '\0' && index + 1 < n)
	{
		if (us1[index] != us2[index])
		{
			return ((int)(us1[index] - us2[index]));
		}
		index++;
	}
	return ((int)(us1[index] - us2[index]));
}