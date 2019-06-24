#include "rush.h"
#include <stdio.h>

char		*ft_sbtlejoin(char *old, char *ajout)
{
	char	*new;

	if (!old && !ajout)
		return (NULL);
	else if (!old)
		return (ft_strdup(ajout));
	else if (!ajout)
		return (old);
	new = ft_strjoin(old, ajout);
	return (new);
}

t_word  stock(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int leng = 0; 

    t_word *tmp;
    t_word *word;
    /*while (str[i])
    {
        if (str[i] == '\n')
            leng++;
    }
    i = 0;
            printf("%d\n", leng);
    word->id = (char**)malloc(sizeof(char*) * leng);
    word->txt = (char**)malloc(sizeof(char*) * leng);*/
    while (str[i])
    {
            while (str[i] >= '0' && str[i] <= '9')
            {
                tmp->id[j][k] = str[i];
                k++;
                i++;
            }
            word->id[j] = (char*)malloc(sizeof(char) * k);
            word->id[j] = tmp->id[j];
            k = 0;
            while(str[i] == ' ' || str[i] == '\t' || str[i] == ':')
            i++;
            while (str[i] != '\n')
            {
                tmp->txt[j][l] = str[i];
                l++;
                i++;
            }
            word->txt[j] = (char*)malloc(sizeof(char) * l);
            word->txt[j] = tmp->txt[j];
            l = 0;
            j++;  
    }
    return (*word);
}

int main(int argc, char **argv) {
    char    *line;
    int     fd;
    char	*temp;
    char	buff[2];
    fd = open(argv[1],O_RDONLY);
        printf("fd = %d\n", fd);
    
    while (read(fd, buff, 1) > 0 )
    {
        temp = line;
        
		buff[1] = '\0';
        if (!(line = ft_sbtlejoin(line, buff)))
			return (0);
		if (temp)
			free(temp);

    }
    line = ft_sbtlejoin(line, "\0");
    printf("%s\n" , line);
    stock(line);
    close(fd);
    return (0);
}