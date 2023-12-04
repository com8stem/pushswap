#include "libft.h"

void	move_tofrom(const unsigned char *from, unsigned char *to, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i > 0)
	{
		to[i] = from[i];
		i--;
	}
	to[i] = from[i];
}

void	move_fromto(const unsigned char *from, unsigned char *to, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*from;
	unsigned char		*to;

	to = (unsigned char *)dst;
	from = (const unsigned char *)src;
	if (to > from && (size_t)(to - from) < len)
	{
		move_tofrom(from, to, len);
	}
	else if (from > to && (size_t)(from - to) < len)
	{
		move_fromto(from, to, len);
	}
	else
		ft_memcpy(to, from, len);
	return (dst);
}