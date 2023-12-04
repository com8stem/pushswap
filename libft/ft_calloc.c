#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	byte;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	byte = count * size;
	mem = malloc(byte);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, byte);
	return (mem);
}