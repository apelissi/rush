#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 5

typedef	struct		s_word
{
	char    **txt;
	char    **id;
}					t_word;

char	            *ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
size_t              ft_strlen(const char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);


#endif