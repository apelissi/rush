#include "rush.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
size_t		ft_strlen(const char *str)
{
	int nbrc;

	nbrc = 0;
	while (*str != '\0')
	{
		str++;
		nbrc++;
	}
	return (nbrc);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*r;
	unsigned int	i;

	i = 0;
	if (!s || !(r = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strdup(const char *src)
{
	int		n;
	int		p;
	char	*str;

	p = 0;
	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}
	if (!(str = (char*)malloc(sizeof(*src) * n + 1)))
		return (NULL);
	while (src[p] != '\0')
	{
		str[p] = src[p];
		p++;
	}
	str[p] = '\0';
	return (str);
}

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}



