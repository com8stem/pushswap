#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	result = (char *)malloc(ft_strlen(s) + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		result[index] = (*f)(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}