#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_origin;

	dest_origin = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_origin);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s1);
	dest = (char *)malloc(len + 1);
	if (s1 == NULL)
	{
		return (NULL);
	}
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_strcpy(dest, s1);
	return (dest);
}