#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*mem;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	mem = malloc(sizeof(char) * (len + 1));
	if (mem == NULL)
		return (NULL);
	ft_strlcpy(mem, s + start, len + 1);
	return (mem);
}