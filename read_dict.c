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

char  **stock(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int leng = 0; 
    int len = 0; 

    char tmpid[100][100];
    char tmptxt[100][100];
    t_word *word;
    while (str[i])
    {
        if (str[i] == '\n')
            leng++;
        i++;
    }
    i = 0;
            printf("%d\n", leng);
    **tmpid = malloc(sizeof(char*) * leng);
    **tmptxt = (char**)malloc(sizeof(char*) * leng);
    while (str[i])
    {
        printf("zozo");
            tmpid[j] = (char*)malloc(sizeof(char) * 100);
            while (str[i] >= '0' && str[i] <= '9')
            {
                tmpid[j][k] = str[i];
                k++;
                i++;
            }
            //word->id[j] = (char*)malloc(sizeof(char) * k);
            //word->id[j] = tmpid;
            k = 0;
            while(str[i] == ' ' || str[i] == '\t' || str[i] == ':')
            i++;
            tmptxt[j] = (char*)malloc(sizeof(char) * 100);
            while (str[i] != '\n')
            {
                tmptxt[j][l] = str[i];
                l++;
                i++;
            }
            //word->txt[j] = (char*)malloc(sizeof(char) * l);
            //word->txt[j] = tmptxt;
            l = 0;
            j++; 
            i++;
    }
    return (**tmptxt);
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